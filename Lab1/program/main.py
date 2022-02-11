from function import *

# називаємо вихідний файл
print("Enter input file: ")
name = input()
name = name + ".txt"

# вводимо текст з консолі, поки не буде натиснуто клавішу Ctrl + D/Command + D
text_to_input = capture_text()

# записуємо текст у файл name
write_text(name, text_to_input)

# записуємо текст з файлу name у змінну text
text = read_file(name)
print(f"Text on input:\n{text}\n")

# переписуємо компоненти тексту
lines = last_word_letter(text)

# називаємо створений файл
name2 = "New" + name

# записуємо текст у файл name2
write_to_file(name2, lines)
output_text = read_file(name2)
print(f"Text on output:\n{output_text}\n")