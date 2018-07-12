#!/usr/local/bin/python3

# Given Values
annualInterestRate = 0.18
balance = 999999 
########

monthlyInterestRate = annualInterestRate / 12.0
lower_bound = balance / 12.0
higher_bound = balance * ((1 + monthlyInterestRate)**12) / 12.0
guess = (lower_bound + higher_bound) / 2


def bal(b, l, h, g):

    for i in range(0, 12):
        month_unpaid_balance = b - g
        updated_balance = month_unpaid_balance + \
            (month_unpaid_balance * monthlyInterestRate)
        b = updated_balance

    print("First balance: " + str(updated_balance) +
          " First guess: " + str(g) + " High: " + str(h) +
          " Low: " + str(l))

    if updated_balance <= 0 and abs(g - h) < 0.01:
        print("Lowest Payment: " + str(round(g, 2)) +
              " High: " + str(h) + " Low: " + str(l))

    elif abs(updated_balance) < h:
        low = g
        print("2: updated_balance: " + str(round(g, 2)) +
              " High: " + str(h) + " Low: " + str(low))
        g = (low + h) / 2
        print("new guess: " + str(round(g, 2)))
        bal(updated_balance, low, h, g)

    elif abs(updated_balance) > h:
        high = g
        print("2: updated_balance: " + str(round(g, 2)) +
              " High: " + str(high) + " Low: " + str(l))
        g = (l + high) / 2
        print("new guess: " + str(round(g, 2)))
        bal(updated_balance, l, high, g)


bal(balance, lower_bound, higher_bound, guess)
