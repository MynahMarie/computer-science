#!/usr/local/bin/python3

# Given Values
annualInterestRate = 0.18
balance = 999999
########

monthlyInterestRate = annualInterestRate / 12.0
lower_bound = balance / 12.0
higher_bound = balance * ((1 + monthlyInterestRate)**12) / 12.0
guess = (lower_bound + higher_bound) / 2.0
updatedBalance = balance
epsilon = 0.01

while abs(updatedBalance) > epsilon:
    updatedBalance = balance

    for month in range(12):
         month_unpaid_balance = updatedBalance - guess
         updatedBalance = month_unpaid_balance + (month_unpaid_balance * monthlyInterestRate)

    if updatedBalance > 0:
        lower_bound = guess
    else:
        higher_bound = guess

    guess = (higher_bound + lower_bound) / 2

print("Lowest payment: " + str(round(guess, 2)))
