from datetime import datetime
#import numpy as np
import pickle

class Time:

    minutes = 0
    hours = 0

    def createTime(args):
        time = Time()
        time.hours = int(args[:2])
        time.minutes = int(args[3:])

        return time

    def toString(self):

        if self.hours < 10 and self.minutes < 10:
            time = "0" + str(self.hours) + ":" + "0" + str(self.minutes)
        elif self.minutes < 10 and self.hours >= 10:
            time = str(self.hours) + ":" + "0" + str(self.minutes)
        elif self.hours < 10 and self.minutes >= 10:
            time = "0" + str(self.hours) + ":" + str(self.minutes)
        elif self.hours >= 10 and self.minutes >= 10:
            time = str(self.hours) + ":" + str(self.minutes)
        return time

    def __init__(self):
        self.minutes = int()
        self.hours = int()


class Task:
    name = str()
    time_start = Time()
    duration = Time()

    def __init__(self,name,time_start,duration):
        self.name = name
        self.time_start = Time.createTime(time_start)
        self.duration = Time.createTime(duration)


class FreeT:
    start = Time()
    finish = Time()
    free_dur = Time()

    def __init__(self,start,finish,free_dur):
        self.start = Time.createTime(start)
        self.finish = Time.createTime(finish)
        self.free_dur = Time.createTime(free_dur)



def time_to_int(time: str):
    h = time[:2]
    m = time[3:]
    number = int(h) * 60 + int(m)
    return number

def hours(time: str):
    flag = True
    h = time[:2]
    m = time[3:]
    if int(h) >= 0 and int(h) <= 23:
        if int(m) >= 0 and int(m) <= 59:
            flag = False

    return flag

def dur(time: str, duration: str, times: str):
    flag = False
    number = time_to_int(time)
    if len(time) != 0:
        if len(times) != 0:
            num_t = len(times)-1
            time_before = time_to_int(times[num_t])
            d = time_to_int(duration)
            if time_before + d > number:
                flag = True
    return flag

def verifyName(name: str):
    while (len(name) > 20 or len(name) < 1):
        print("Enter a name again: ")
        name = input();
    return name

def verifyTime(time: str, duration, times):
    flag_hours = hours(time)
    flag_duration = dur(time, duration, times)
    while not (len(time) == 5 and time[2] == ':' and not flag_hours and not flag_duration):
        print("Enter a time again: ")
        time = input()
        flag_hours = hours(time)
        flag_duration = dur(time, duration, times)

    return time

def verifyDuration(duration: str, time: str):
    flag_hours = hours(duration)
    flag_dif = False
    if time_to_int(duration) + time_to_int(time) > 1440:
        flag_dif = True
    while len(duration) != 5 or duration[2] != ':' or flag_hours or flag_dif:
        print('Enter a duration again: ')
        duration = input()
        flag_hours = hours(duration)
        flag_dif = False
        if time_to_int(duration) + time_to_int(time) > 1440:
            flag_dif = True
    return duration

def duration_normal(duration: str, time: str):
    flag = True
    if time_to_int(duration) + time_to_int(time) == 1440:
        flag = False
    return flag

def int_to_time(num: int):
    h = num // 60
    m = num % 60
    if h < 10 and m < 10:
        time ="0" + str(h) + ":" + "0" + str(m);
    elif m < 10 and h >= 10:
        time = str(h) + ":" + "0" + str(m);
    elif h < 10 and m >= 10:
        time = "0" + str(h) + ":" + str(m);
    elif h >= 10 and m >= 10:
        time = str(h) + ":" + str(m);
    return time;


def capture_text(name_f):
    """
    Читаємо текст строками
    """
    flag = 'y'
    duration = '0'
    times = []
    # durations = []
    # text = np.array([])
    # text = []
    size = 0
    #tasks = Task()
    with open(name_f, 'wb') as file:
        while flag == 'y':
            print('Enter a name of task(maximum number of characters - 20): ')
            task_name = input()
            task_name = verifyName(task_name)


            print('Enter a event start time in this format HH:MM: ')
            time_start = input()
            time_start = verifyTime(time_start, duration, times)
            times.append(time_start)

            print('Enter a duration in this format HH:MM: ')
            duration = input()
            duration = verifyDuration(duration, time_start)


            tasks = Task(task_name,time_start,duration)

            pickle.dump(tasks, file)

            size+=1

            if duration_normal(duration, time_start):
                print('\nDo you want to continue input task?[y/n]: ')
                flag = input()
            else:
                flag = 'n'


    return size

def write_text(name_f: str, text):
    """
    Записуємо текст у файл
    """
    with open(name_f, "wb") as file:
        for i in range(len(text)):
            pickle.dump(text[i], file)

def next_event(text):
    min = 1440
    current_datetime = datetime.now()
    h = current_datetime.hour
    m = current_datetime.minute
    if h >= 10 and m < 10:
        print('Time now: ' + str(h) + ':' + '0' + str(m))
    elif h < 10 and m < 10:
        print('Time now: ' + '0' + str(h) + ':' + '0' + str(m))
    elif h < 10 and m >= 10:
        print('Time now: ' + '0' + str(h) + ':' + str(m))
    elif h >= 10 and m >= 10:
        print('Time now: ' + str(h) + ':' + str(m))
    dif = 0
    j = 0
    time_now = h * 60 + m
    for i in range(len(text)):
        ht = text[i].time_start.hours
        mt = text[i].time_start.minutes
        time_list = ht * 60 + mt
        dif = time_list - time_now
        if dif > 0 and dif < min:
            j = i
            min = dif
    if dif > 0:
        print('Next event: ' + text[j].name + ", " + text[j].time_start.toString() + ", " + "duration: " + text[j].duration.toString())
    else:
        print('Today you have no more business!!!')

def free_time(text, name_f):
    size = 0
    task_flag = False
    start = "13:00"
    finish = "23:59"
    free_dur = "10:59"
    file = open(name_f, "wb")
    for i in range(len(text)):
        time_n = text[i].time_start.hours * 60 + text[i].time_start.minutes
        dur_n = text[i].duration.hours * 60 + text[i].duration.minutes
        if time_n + dur_n >= 780:
            start = int_to_time(time_n + dur_n)
            if i + 1 < len(text):
                finish = int_to_time(text[i+1].time_start.hours * 60 + text[i+1].time_start.minutes)
            else:
                finish = '23:59'
            free_dur = int_to_time(time_to_int(finish) - time_to_int(start))
            free_text = FreeT(start, finish, free_dur)
            pickle.dump(free_text, file)
            task_flag = True
            size+=1
    if task_flag == False:
        free_text = FreeT(start, finish, free_dur)
        pickle.dump(free_text, file)

    return size

def read_file(name_f: str, size):
    """
    Читає текст з файлу
    """
    text = []
    print("Text on input:" + "\n")
    print(size)
    with open(name_f, "rb") as file:
        for i in range(size):
            text.append(pickle.load(file))
            str_t = text[i].name + ", " + text[i].time_start.toString() + ", " + "duration: " + text[i].duration.toString()
            print(str(str_t) + "\n")

    return text

def read_file2(name_f: str, size):
    """
    Читає текст з файлу
    """
    text = []
    print("Text on output:" + "\n")
    with open(name_f, "rb") as file:
        for i in range(size):
            text.append(pickle.load(file))
            str_t = text[i].start.toString() + "-" + text[i].finish.toString() + ", " + "duration: " + text[i].free_dur.toString()
            print(str(str_t) + "\n")



