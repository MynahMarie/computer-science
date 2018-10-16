#!/usr/local/bin/python3

# Given Values
annualInterestRate = 0.2
balance = 3926 
########

fixed_amount = 10
mir = annualInterestRate / 12.0
updated_balance = balance
prev_balance = balance


def bal(fa, pb):
    print(str(fa), str(pb))    
    for i in range(0, 12):
        month_unpaid_balance = pb - fa
        updated_balance = month_unpaid_balance + (month_unpaid_balance * mir)
        pb = updated_balance

    if updated_balance <= 0:
        print("my final balance: " + str(updated_balance))
        print("Lowest Payment: " + str(fa))
    else:
        print("updated_balance: " + str(updated_balance))
        print("fixed amount: " + str(fa))
        bal((fa + 10), balance)


bal(fixed_amount, balance)
# Should produce 440
