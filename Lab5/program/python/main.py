from function import *
CatalogPT = []
CatalogF = []

print("Enter number of industrial goods: ")
n = input()
CatalogPT = recordIndTov(CatalogPT, n)

print("Enter number of foodstuffs: ")
m = input()
CatalogF = recordFood(CatalogF, m)

overdue(CatalogF, m)

goodsStock(CatalogPT, n)

del CatalogPT
del CatalogF

