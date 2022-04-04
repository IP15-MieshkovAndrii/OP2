from function import *

# називаємо вихідний файл
print("Enter input file: ")
name = input()
name = name + ".dat"

# вводимо текст з консолі
size = capture_text(name)

# записуємо текст з файлу name у змінну text
text = read_file(name, size)

#знаходимо наступну подію
next_event(text)

# називаємо створений файл
name2 = "New" + name
# переписуємо компоненти тексту
new_size = free_time(text, name2)
#читаємо файл
read_file2(name2, new_size)
