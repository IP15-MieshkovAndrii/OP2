from classes import *
def verifyName(name):
    letter = True
    for i in range(len(name)):
        if not name[0].isalpha():
            letter = False
            str = "The name must start with a letter.\nEnter again: "
            break
        if not name[i].isspace() and not name[i].isalpha():
            letter = False
            str = "The name consists only of letters.\nEnter again: "
            break
    if not letter:
        print(str)
        name = input()
        name = verifyName(name)

    return name

def verifyTime(date):
    obj = Tovar("0","0",0,0)
    flag = False
    d = obj.days(date)
    m = obj.month(date)
    y = obj.years(date)

    if m >= 1 and m <= 12:
        if m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12:
            if d >= 1 and d <= 31:
                flag = True

        if m == 4 or m == 6 or m == 9 or m == 11:
            if d >= 1 and d <= 30:
                flag = True

        else:
            if y % 4 == 0:
                if d >= 1 and d <= 29:
                    flag = True

            else:
                if d >= 1 and d <= 28:
                    flag = True
    del obj
    return flag


def verifyDate(date):
    format = True
    for i in range(len(date)):
        if len(date) > 10:
            format = False
            str = "Too many characters.\nEnter again: "
            break
        if len(date) < 10:
            format = False
            str = "Too few characters.\nEnter again: "
            break

        if i == 2 or i == 5:
            if date[i] != '.':
                format = False
                str="Not the right format.\nEnter again: "
                break
        if i != 2 and i != 5:
            if not date[i].isdigit():
                format = False
                str = "Not the right format.\nEnter again: "
                break
    if format:
        time = verifyTime(date)
        if not time:
            str = "Non-existent date.\nEnter again: "

    if not format or not time:
        print(str)
        date = input()
        date = verifyDate(date)

    return date

def verifyTerm(term, dateM):
    obj = Tovar("0","0",0,0)
    flag = True
    dT = obj.days(term)
    mT = obj.month(term)
    yT = obj.years(term)
    dM = obj.days(dateM)
    mM = obj.month(dateM)
    yM = obj.years(dateM)
    if yT < yM:
        flag = False
    elif yT == yM:
        if mT < mM:
            flag = False
        elif mT == mM:
            if dT <= dM:
                flag = False

    if not flag:
        print("The expiration date may not be less than the date of manufacture.\nEnter again: ")
        term = input()
        term = verifyTerm(term, dateM)
    del obj
    return term

def toFixed(numObj, digits=0):
    return f"{numObj:.{digits}f}"

def verifyPrice(price):
    pr_str = str(price)
    if not pr_str.isnumeric():
        x = pr_str.find(".")
        doz = pr_str[x+1:]
        if len(doz) > 2:
            print("The number of characters up to tenths.\nEnter again: ")
            price = input()
            price = verifyPrice(price)
    return price
