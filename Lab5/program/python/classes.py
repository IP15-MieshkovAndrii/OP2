class Tovar:
    def __init__(self, name, dateOfManufacture, price, number):
        self.name = name
        self.dateOfManufacture = dateOfManufacture
        self.price = price
        self.number = number

    def __del__(self):
        pass

    def days(self, date):
        return int(date[:2])
    def month(self, date):
        return int(date[3:5])
    def years(self, date):
        return int(date[6:])
    def get(self):
        print(self.name + " - " + self.dateOfManufacture + ", " + str(self.price) + "₴, " + str(self.number) + " units")
    def getDate(self):
        return self.dateOfManufacture
    def who_stale(self, date1, date2):
        fresh = True
        nd = self.days(date1)
        td = self.days(date2)
        nm = self.month(date1)
        tm = self.month(date2)
        ny = self.years(date1)
        ty = self.years(date2)
        if (ny > ty):
            fresh = False
        elif (ny == ty):
            if (nm > tm):
                fresh = False
            elif (nm == tm):
                if (nd >= td):
                    fresh = False
        return fresh
    def who_stale(self, d, m, y, date):
        fresh = True
        td = self.days(date)
        tm = self.month(date)
        ty = self.years(date)
        if y > ty:
            fresh = False
        elif y == ty:
            if m > tm:
                fresh = False
            elif m == tm:
                if d >= td:
                    fresh = False
        return fresh
    def sum(self):
        sum = float(self.price) * int(self.number)
        return sum

class IndustrialTovar(Tovar):
    def __init__(self, name, dateOfManufacture, price, number, conditions, place):
        Tovar.__init__(self, name, dateOfManufacture, price, number)
        self.conditions = conditions
        self.place = place
    def __del__(self):
        pass
    def get(self):
        Tovar.get(self)
        print("Storage conditions: " + self.conditions + "\nLocation of goods: " + self.place + "\n")

    def in_stock(self):
        if self.place == "stock":
            return True
        else:
            return False

class Foodstuff(Tovar):
    def __init__(self, name, dateOfManufacture, price, number, term):
        Tovar.__init__(self, name, dateOfManufacture, price, number)
        self.term = term
    def __del__(self):
        pass

    def get(self):
        Tovar.get(self)
        print("Shelf life until " + self.term + "\n")
    def getTerm(self):
        return self.term









