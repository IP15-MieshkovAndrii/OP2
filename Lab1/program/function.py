def capture_text():
    """
    Читаємо текст строками, до натиснення комбінації Ctrl + D/Command + D
    """
    print('Enter your text\nPress Enter to go to the next line\nPress Ctrl + D/Command + D - to end writing')

    import sys
    text = sys.stdin.read()

    # видаляємо зайвий символ \n
    text = text[:len(text) - 1]

    print(f"Full text:\n{text}\n")

    return text


def write_text(name_f: str, text: str):
    """
    Записуємо текст у файл
    """
    file = open(name_f, 'w')
    file.write(text)
    file.close()


def last_word_letter(text: str):
    """
    Вставляємо на початок рядка першу літеру останнього слова у кожному рядку
    """
    lines = text.split('\n')
    for i in range(len(lines)):
        word = lines[i].split()
        letter = word[-1][0]
        lines[i] = letter + lines[i]
    return lines



def write_to_file(name: str, lines: str):
    """
    Записує текст у файл
    """
    write_file = open(name, 'w')
    for i in range(len(lines)):
        write_file.write(f"{lines[i]}\n")

    write_file.close()


def read_file(file_name: str):
    """
    Читає текст з файлу
    """
    file = open(file_name, 'r')
    text = file.read()
    file.close()

    return text