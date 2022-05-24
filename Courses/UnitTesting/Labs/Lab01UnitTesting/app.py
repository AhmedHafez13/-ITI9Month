def odd_or_even(number):
    if number == 0:
        return "zero"
    if number % 2 == 0:
        return "even"
    elif number % 2 != 0:
        return "odd"


def is_odd_number(number):
    if number % 2 == 0:
        return False
    else:
        return True


def get_occur_count(text, key):
    return text.count(key)
