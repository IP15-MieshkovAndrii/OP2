from verify import *
from datetime import datetime

def recordIndTov(catalog, n):
    for i in range(int(n)):
        print("Name: ")
        name = input()
        name = verifyName(name)

        print("Date of manufacture(DD.MM.YYYY): ")
        dateOfManufacture = input()
        dateOfManufacture = verifyDate(dateOfManufacture)

        print("Price: ")
        price = input()
        price = verifyPrice(price)

        print("Number of units: ")
        number = input()

        print("Terms of transportation: ")
        conditions = input()

        print("Location\n1 - in stock\n2 - in the trading hall")
        n_pl = input()
        while n_pl != "1" and n_pl != "2":
            print("You can only choose 1 or 2\nEnter again: ")
            n_pl = input()
        if n_pl == "1":
            place = "stock"
        else:
            place = "hall"

        catalog.append(IndustrialTovar(name, dateOfManufacture, price, number, conditions, place))
    return catalog

def recordFood(catalog, m):
    for i in range(int(m)):
        print("Name: ")
        name = input()
        name = verifyName(name)

        print("Date of manufacture(DD.MM.YYYY): ")
        dateOfManufacture = input()
        dateOfManufacture = verifyDate(dateOfManufacture)

        print("Price: ")
        price = input()

        print("Number of units: ")
        number = input()

        print("Expiration date(DD.MM.YYYY): ")
        term = input()
        term = verifyDate(term)
        term = verifyTerm(term, dateOfManufacture)

        catalog.append(Foodstuff(name, dateOfManufacture, price, number, term))
    return catalog

def overdue(catalog, m):
    OverSum = 0
    datenow = datetime.now()
    dNow = datenow.day
    mNow = datenow.month
    yNow = datenow.year
    for i in range(int(m)):
        catalog[i].get()
        Obj = catalog[i]
        if not Obj.who_stale(dNow, mNow, yNow, Obj.getTerm()):
            OverSum += Obj.sum()
    if OverSum != 0:
        print("The total amount of expired foodstuffs: " + toFixed(OverSum, 2) + "₴\n")
    else:
        print("No expired foodstuffs.\n")

def goodsStock(catalog, n):
    OverSum = 0
    for i in range(int(n)):
        catalog[i].get()
        Obj = catalog[i]
        if Obj.in_stock():
            OverSum += Obj.sum()
    if OverSum != 0:
        print("The total amount of goods in stock: " + toFixed(OverSum, 2) + "₴\n")
    else:
        print("No goods in stock.\n")
