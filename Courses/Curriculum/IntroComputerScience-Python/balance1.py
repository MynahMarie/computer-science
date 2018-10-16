#!/usr/local/bin/python3

# Given Values
balance = 484 
annualInterestRate = 0.2
monthlyPaymentRate = 0.04
#########

updated_balance = balance
prev_balance = balance
mir = annualInterestRate / 12.0
paid_amount = 0

for i in range(0, 12):
    min_month_payment = round((monthlyPaymentRate * prev_balance), 2)
    paid_amount += min_month_payment
    month_unpaid_balance = prev_balance - min_month_payment
    updated_balance = round((month_unpaid_balance + (mir *
                            month_unpaid_balance)), 2)
    prev_balance = updated_balance
    print("Month " + str(i), "min monthly payment: " + str(min_month_payment),
          "remaining balance: " + str(updated_balance))

print("Remaining balance: " + str(round(updated_balance, 2)))
