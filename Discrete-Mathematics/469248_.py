#coding: utf-8

def parse_cnf(expr):
    expr = expr.replace("!", "~")
    clauses = expr.split("&")
    return set(frozenset(clause.replace("(", "").replace(")", "").split("|")) for clause in clauses)

def resolve(C1, C2):
    res = set()
    for literal in C1:
        if literal[0] == "~":
            neg_literal = literal[1:]
        else:
            neg_literal = "~" + literal
        if neg_literal in C1:
            return {1}
        if neg_literal in C2:
            res = (C1 | C2) - {literal, neg_literal}
            return res
    return None

def resolution(clauses):
    S0, S1, S2 = set(), clauses, set()

    while True:
        def run(S0, S1, S2, S_0, S_1):
            for C1 in S_0:
                for C2 in S_1:
                    if C1 == C2:
                        continue
                    res = resolve(C1, C2)
                    if res is not None:
                        if not res:
                            return "NO"
                        if res == {1}:
                            return "YES"
                        if res not in S0 and res not in S1:
                            S2.add(frozenset(res))
            return None
        res = None
        res = run(S0, S1, S2, S0, S1)
        if res is not None:
            return res
        res = run(S0, S1, S2, S1, S1)
        if res is not None:
            return res
        if not S2:
            return "YES"
        S0.update(S1)
        S1 = S2.copy()
        S2.clear()


expr = raw_input()  # 
clauses = parse_cnf(expr)

result = resolution(clauses)
print result  # 
