#encoding: utf-8

import json
import os
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

# 切换到文件的绝对路径
absolute_path = os.path.dirname(__file__)
# absolute_path = os.path.abspath("./")
print(absolute_path)
os.chdir(absolute_path)
config = json.load(open("config.json"))
print(config)


class LexueDriver:
    def __init__(self):
        from selenium import webdriver
        self.website_login_url = config["website_login_url"]
        self.user_account = config["user_account"]
        self.user_password = config["user_password"]
        self.courses = config["courses"]
        options = webdriver.ChromeOptions()
        options.add_argument('--headless')  # 无头模式
        options.add_argument('--disable-gpu')  # 禁用 GPU
        options.add_argument('--no-sandbox')  # 解决无权限问题（某些系统下）
        options.add_argument('--disable-dev-shm-usage')  # 共享内存的禁用
        options.add_experimental_option('excludeSwitches', ['enable-logging', 'enable-automation'])
        self.driver = webdriver.Chrome(options=options)
    def login(self):
        import time
        self.driver.get(self.website_login_url)
        time.sleep(1)

        login_form_path = '/html/body/div[1]/div[2]/div/section/'
        self.driver.find_element(By.XPATH, login_form_path + 'div[2]/div[1]/div/form/div/div[1]/div[1]/input').send_keys(self.user_account)
        self.driver.find_element(By.XPATH, login_form_path + 'div[2]/div[1]/div/form/div/div[1]/div[2]/input[1]').send_keys(self.user_password)

        time.sleep(0.5)

        self.driver.find_element(By.XPATH, login_form_path + "/div[2]/div[1]/div/form/div/div[3]/a").click()

        time.sleep(2)
    def get_problem_of_course(self, course):
        os.chdir(course)
        # 得到当前文件夹的所有文件
        file_list = os.listdir()
        print(file_list)
        problem_list = []
        json_list = {}
        if os.path.exists(f"{course}.json"):
            json_list = json.load(open(f"{course}.json", encoding="utf-8"))

        for file in file_list:
            # 将文件切割橙数字和后缀名
            file_name_list = file.split(".")
            if len(file_name_list) != 2:
                continue
            name = file_name_list[0]
            # 找到name里第一个出现的数字（一长串）
            # 使用正则表达式
            from re import findall
            result = findall(r"\d+", name)
            if not result:
                continue
            id = result[0]
            suffix = file_name_list[1]
            if suffix in ("cpp", "c", "java", "py") and int(id) > 10000:
                problem_list.append(id)
        # problem_list.sort()
        problem_list = sorted(list(set(problem_list)), key=lambda x: int(x))
        print(problem_list)

        # with open(f"{course}.md", "w", encoding="utf-8") as f:
        for problem_id in problem_list:
            if problem_id in json_list:
                continue
            self.driver.get(f"{self.website_login_url}/mod/programming/view.php?id={problem_id}")
            print(problem_id, self.driver.current_url)

            try:
                # 等待页面加载完成并等待 h2 元素出现
                t = WebDriverWait(self.driver, 1).until(
                    EC.presence_of_element_located((By.XPATH, "/html/body/div[2]/div[3]/div/div/section/div[1]/h2"))
                )
                print(t.text)
                json_list[str(problem_id)] = t.text

            except Exception as e:
                self.driver.get(f"{self.website_login_url}/mod/programming/view.php?pid={problem_id}")
                print(problem_id, self.driver.current_url)
                try:
                    t = WebDriverWait(self.driver, 1).until(
                        EC.presence_of_element_located((By.XPATH, "/html/body/div[2]/div[3]/div/div/section/div[1]/h2"))
                    )
                    print(t.text)
                    json_list[str(problem_id)] = t.text
                except Exception as e:
                    print(e)
                    json_list[problem_id] = "本题目丢失了呜呜呜"
                    print(f"当前题目丢失了呜呜呜")
        # json_list = sorted(json_list)
        new_json_list = sorted(json_list.items(), key=lambda x: int(x[0]))
        new_json_list = [x for x in new_json_list if x[0] in problem_list]
        json_list = dict(new_json_list)

        # for key, value in json_list.items():
        #     print(key, value)
        print(json_list)
        json.dump(json_list, open(f"{course}.json", "w", encoding="utf-8"), ensure_ascii=False, indent=4)
        with open(f"README.md", "w", encoding="utf-8") as f:
            f.write("| 题号 | 题目名称 |\n| --- | --- |\n")
            for key, value in json_list.items():
                f.write(f"| {key} | {value} |\n")

        os.chdir("..")
    def get_problem_list(self):
        os.chdir("..")
        print(os.getcwd())
        for course in self.courses:
            self.get_problem_of_course(course)

driver = LexueDriver()
driver.login()
driver.get_problem_list()
