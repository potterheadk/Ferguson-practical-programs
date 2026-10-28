# Python Practical Cheat Sheet and Study Guide

This guide is based on the Python work in this folder: Week 1, Python
Assignments 1–6, and `supermarket.ipynb`. It explains the concepts in simple
terms, gives small examples, and finishes with a supermarket billing program
that combines the most useful practical-exam topics.

> **How to study:** First understand the small examples in the tables. Then
> practise writing the supermarket program without looking at the solution.
> In a practical exam, read the exact question and adapt the pattern rather
> than copying a program that does something slightly different.

## 1. Assignment topic map

| Work in this folder | Topics covered |
|---|---|
| Week 1 | Menu-driven `while` loop, factorial, prime check, Fibonacci, reversing a number, multiplication table, GCD/LCM, Floyd's triangle, sum of natural numbers |
| Python Assignment 1 | Variables and types, input/output, arithmetic calculator, rectangle area/perimeter, even/odd, simple interest, average, temperature conversion, BMI, comparison |
| Python Assignment 2 | `min()`/`max()`, `while` loops, sums, set iteration, `for`-`else`, prime ranges, substring search/replacement, string slicing/counting/capitalization, character counts, frequency dictionaries |
| Python Assignment 3 | Functions and `return`, vowel counting, `*args`, `**kwargs`, default arguments, manual string reversal, list slicing, dictionary changes, list methods |
| Python Assignment 4 | Custom modules, imports, date/time formatting, lambda functions, `map()`, rounding, adding corresponding list elements |
| Python Assignment 5 | Regular expressions: validate email/mobile/PAN/date/password, extract numbers/hashtags/mentions, detect repeated words, split on delimiters, replace words |
| Python Assignment 6 | Text and binary files, read/write/append, count words, copy selected lines, rename/delete files, directories, current working directory |
| `supermarket.ipynb` | Product dictionary, stock display, repeated purchases, cart/invoice, subtotal, discount, GST, final total |

## 2. Quick concept cheat sheet

| Concept | What it means / when to use it | Small example |
|---|---|---|
| Variable | A named place to store a value. | `price = 25` |
| String (`str`) | Text enclosed in quotes. | `name = "Apple"` |
| Integer (`int`) | Whole number. | `quantity = 3` |
| Float (`float`) | Number that can have a decimal part. | `price = 12.5` |
| Boolean (`bool`) | A truth value: `True` or `False`. | `is_available = True` |
| `type()` | Shows the type of a value. | `print(type(12.5))` |
| `input()` | Reads text typed by the user. It always returns a string. | `name = input("Name: ")` |
| Type conversion | Changes a value to another type. Convert numeric input before arithmetic. | `age = int(input("Age: "))` |
| `print()` | Displays values. | `print("Total:", 10 + 5)` |
| `f`-string | Inserts values into readable text. | `print(f"Total: {10 + 5}")` |
| `if` / `elif` / `else` | Chooses which block to run based on conditions. | `if price > 0: print("Valid")` |
| Comparison | Compares values and returns `True` or `False`. | `5 >= 3` |
| `and`, `or`, `not` | Combines or reverses conditions. | `age >= 18 and has_id` |
| `for` loop | Repeats once for each item in a sequence. | `for item in ["A", "B"]: print(item)` |
| `while` loop | Repeats while a condition remains true; useful for menus. | `while count < 3: count += 1` |
| `range()` | Generates integers for a loop; the ending number is excluded. | `for i in range(1, 4): print(i)` |
| `break` | Exits the nearest loop. | `if choice == 0: break` |
| `continue` | Skips to the next loop repetition. | `if quantity == 0: continue` |
| `for`-`else` | Runs `else` only if the loop ended without `break`; useful for a search. | `for` loop + `else` block; see example below |
| Function | A reusable named block, declared with `def`. | `def double(n): return n * 2` |
| Parameter / argument | Parameter is the function's input name; argument is the value passed. | `double(4)` passes `4` to `n` |
| `return` | Sends a result back to the caller. | `answer = double(4)` |
| Default argument | Uses a value when the caller leaves an argument out. | `def greet(name, msg="Hello"): print(msg, name)` |
| `*args` | Collects any number of positional arguments into a tuple. | `def add(*nums): return sum(nums)` |
| `**kwargs` | Collects keyword arguments into a dictionary. | `def show(**data): print(data)` |
| Recursion | A function calls itself; it must have a stopping/base case. | `def f(n): return 1 if n == 0 else n * f(n-1)` |
| List | Ordered, changeable collection; allows duplicates. | `prices = [10, 20, 10]` |
| Tuple | Ordered, unchangeable collection. | `point = (2, 5)` |
| Set | Collection of unique values; order is not guaranteed. | `ids = {1, 2, 2}` gives `{1, 2}` |
| Dictionary | Stores key-value pairs; useful for products and stock. | `product = {"name": "Tea", "price": 20}` |
| String/list index | Gets one item; indexes start at `0`. | `"Apple"[0]` gives `"A"` |
| Slice | Gets part of a string/list: `sequence[start:stop:step]`. | `[0, 1, 2, 3][::2]` gives `[0, 2]` |
| `in` | Tests whether an item or substring exists. | `"app" in "apple"` is `True` |
| `len()` | Counts items/characters. | `len("cat")` gives `3` |
| `sum()` | Adds the values in an iterable of numbers. | `sum([2, 3])` gives `5` |
| `min()` / `max()` | Gets the smallest/largest value. | `max(2, 9, 4)` gives `9` |
| `map()` | Applies a function to each item; wrap with `list()` to see results. | `list(map(lambda n: n*2, [1, 2]))` gives `[2, 4]` |
| `lambda` | A small anonymous one-expression function. | `square = lambda n: n*n` |
| Module / `import` | A Python file that can be reused by another file. | `import math; print(math.sqrt(9))` |
| `round()` | Rounds a number; second argument gives decimal places. | `round(3.141, 1)` gives `3.1` |
| `datetime` | Standard library module for dates and times. | `from datetime import datetime; print(datetime.now())` |
| File `with open()` | Opens a file and closes it automatically after the block. | `with open("a.txt", "r") as f: text = f.read()` |
| Regular expression (`re`) | Pattern matching for text formats and extraction. | `re.fullmatch(r"\d{4}", "2026")` |
| Exception handling | Handles expected runtime errors, such as invalid numeric input. | `try` / `except`; see the supermarket example |

## 3. Input, output, operators, and conditions

### Input conversion

`input()` returns text, even when the user types digits. Convert it before
doing numeric calculations:

```python
quantity = int(input("Quantity: "))
price = float(input("Price: "))
print(f"Amount: {quantity * price:.2f}")
```

Use `int()` for whole-number quantities and `float()` for prices, averages,
measurements, and percentages. For money in a real system, decimal arithmetic
is preferable; for introductory practicals, `float` plus rounding is usually
the expected level.

### Operators

| Operator | Meaning | Example |
|---|---|---|
| `+` | Add | `4 + 2` → `6` |
| `-` | Subtract | `4 - 2` → `2` |
| `*` | Multiply | `4 * 2` → `8` |
| `/` | Divide; result is usually a float | `5 / 2` → `2.5` |
| `//` | Floor division | `5 // 2` → `2` |
| `%` | Remainder; handy for even/odd | `5 % 2` → `1` |
| `**` | Power | `2 ** 3` → `8` |
| `+=` | Add and assign | `total += price` |

The calculator assignment uses `match`/`case`. A practical can also use
`if`/`elif`, which works in more Python versions:

```python
a = 8
b = 2
operator = "+"

if operator == "+":
    print(a + b)
elif operator == "/":
    if b != 0:
        print(a / b)
    else:
        print("Cannot divide by zero")
else:
    print("Unsupported operator")
```

### Common condition patterns

```python
# Even or odd
number = 7
if number % 2 == 0:
    print("Even")
else:
    print("Odd")

# Range/category check (BMI-style)
score = 72
if score < 40:
    result = "Needs improvement"
elif score < 75:
    result = "Pass"
else:
    result = "High score"
```

Use chained comparisons such as `18.5 <= bmi < 25`. Check boundary values
carefully: every possible value should belong to the intended category.

## 4. Loops and number problems

### `for`, `range`, nested loops

```python
# Prints 1, 2, 3, 4 (stop is excluded)
for number in range(1, 5):
    print(number)

# Small multiplication table
for row in range(1, 4):
    for column in range(1, 4):
        print(row * column, end="\t")
    print()
```

The inner loop runs fully for every outer-loop value. This pattern is used
for multiplication matrices and Floyd's triangle.

### `while` and menu patterns

```python
while True:
    print("1. Say hello")
    print("0. Exit")
    choice = input("Choice: ")

    if choice == "0":
        break
    elif choice == "1":
        print("Hello!")
    else:
        print("Invalid choice")
```

`break` exits the menu. `continue` skips the rest of the current iteration.
For user input, comparing strings avoids a crash on non-numeric menu choices.

`for`-`else` is useful when searching: the `else` block runs only if no
`break` occurred.

```python
values = [2, 4, 6]
target = 5
for value in values:
    if value == target:
        print("Found")
        break
else:
    print("Not found")
```

### Accumulating a total

```python
total = 0
for number in range(1, 5):
    total += number
print(total)  # 10
```

For the first `n` natural numbers, the formula is `n * (n + 1) // 2`.
Use `//` when the expected answer is a whole number.

### Factorial

Factorial is the product of all positive integers up to `n`; by definition,
`0!` is `1`.

```python
def factorial(n):
    if n < 0:
        raise ValueError("Factorial is not defined for negative integers")
    answer = 1
    for number in range(1, n + 1):
        answer *= number
    return answer

print(factorial(5))  # 120
```

The assignment also practises recursion. The same calculation recursively
needs a base case:

```python
def factorial_recursive(n):
    if n == 0:
        return 1
    return n * factorial_recursive(n - 1)
```

### Prime check

A prime is a whole number greater than `1` with exactly two factors: `1` and
itself. `0` and `1` are not prime.

```python
def is_prime(number):
    if number < 2:
        return False
    for divisor in range(2, int(number ** 0.5) + 1):
        if number % divisor == 0:
            return False
    return True

print(is_prime(7))  # True
```

Check a range by calling the function inside a loop:

```python
for number in range(20, 26):
    if is_prime(number):
        print(number, end=" ")
# 23
```

### Fibonacci

Each Fibonacci number is the sum of the two before it: `0, 1, 1, 2, 3, 5...`.

```python
def fibonacci(count):
    first, second = 0, 1
    for _ in range(count):
        print(first, end=" ")
        first, second = second, first + second

fibonacci(5)  # 0 1 1 2 3
```

`_` means the loop counter is intentionally unused.

### Reverse a number, GCD, LCM

```python
# String slicing is a simple way to reverse digits for display.
number = 1234
print(str(number)[::-1])  # 4321

# Euclidean algorithm for GCD
a, b = 24, 18
while b != 0:
    a, b = b, a % b
gcd = a
lcm = 24 // gcd * 18
print(gcd, lcm)  # 6 72
```

If negative integers are possible, decide whether the question expects a
negative sign preserved when reversing. For LCM, handle zero inputs separately
if the question allows them.

### Floyd's triangle pattern

```python
rows = 4
value = 1
for row in range(1, rows + 1):
    for _ in range(row):
        print(value, end=" ")
        value += 1
    print()
```

## 5. Strings, lists, sets, and dictionaries

### Strings

Strings are ordered text. Indexing starts at `0`; slicing's end position is
excluded. Strings cannot be changed in place, so methods return a new string.

```python
word = "apple"
print(word[0])            # a
print(word[1:4])          # ppl
print(word[::-1])         # elppa
print(word.upper())       # APPLE
print("app" in word)      # True
print(word.count("p"))    # 2
print(word.replace("p", "b"))  # abble
```

Take three characters around the middle of a string:

```python
text = "Python"
middle = len(text) // 2
print(text[middle - 1:middle + 2])  # tho
```

Useful character checks: `ch.isalpha()`, `ch.isupper()`, `ch.islower()`,
`ch.isdigit()`, and `ch.isspace()`.

Count vowels without case sensitivity:

```python
text = "Hello World"
vowels = "aeiou"
count = 0
for character in text.lower():
    if character in vowels:
        count += 1
print(count)  # 3
```

### Lists

Lists keep order and can be changed. Their methods are common in practical
questions:

| Operation | What it does | Small example |
|---|---|---|
| `append(x)` | Adds `x` at the end | `items.append("Milk")` |
| `insert(i, x)` | Inserts before index `i` | `items.insert(0, "Bread")` |
| `remove(x)` | Removes the first matching value | `items.remove("Milk")` |
| `pop(i)` | Removes and returns index `i` (last item if omitted) | `last = items.pop()` |
| `sort()` | Sorts the list in place | `numbers.sort()` |
| `len(items)` | Counts items | `len(items)` |
| `items[start:stop:step]` | Takes a slice | `items[::2]` |

```python
numbers = [4, 1, 3]
numbers.append(2)
numbers.insert(1, 9)
numbers.remove(4)
numbers.sort()
print(numbers)
```

`sort()` changes the existing list. `sorted(numbers)` instead returns a new
sorted list.

### Sets

Sets store unique values. They are useful for membership checks when order
does not matter:

```python
available_codes = {101, 102, 103}
print(102 in available_codes)  # True
```

### Dictionaries

A dictionary maps a unique key to a value. Use a dictionary for product
records, word counts, or a cart:

```python
product = {"name": "Rice", "price": 60, "stock": 10}
print(product["price"])  # 60

product["price"] = 65   # update
product["category"] = "Grocery"  # add
del product["stock"]    # delete
```

Use `.items()` to loop over both keys and values:

```python
prices = {"Tea": 20, "Coffee": 30}
for name, price in prices.items():
    print(name, price)
```

### Character-frequency dictionary

```python
frequency = {}
for character in "hello":
    if character in frequency:
        frequency[character] += 1
    else:
        frequency[character] = 1
print(frequency)  # {'h': 1, 'e': 1, 'l': 2, 'o': 1}
```

## 6. Functions and functional tools

### Define, call, and return

```python
def area_of_rectangle(length, width):
    return length * width

area = area_of_rectangle(5, 3)
print(area)  # 15
```

Use `return` when the caller needs to use the result. `print()` only displays
it; it does not return the displayed value.

### Default parameters, `*args`, `**kwargs`

```python
def greet(name, message="Hello"):
    print(f"{message}, {name}")

greet("Asha")                 # Hello, Asha
greet("Asha", "Good morning") # Good morning, Asha

def add_numbers(*numbers):
    return sum(numbers)

print(add_numbers(2, 3, 4))  # 9

def print_details(**details):
    for key, value in details.items():
        print(f"{key}: {value}")

print_details(name="Asha", city="Pune")
```

`*args` gathers extra positional arguments into a tuple. `**kwargs` gathers
extra named arguments into a dictionary. Do not name a variable `sum`, `list`,
or `str`; it hides Python's built-in function with that name.

### `lambda`, `map()`, and `round()`

```python
double = lambda number: number * 2
print(double(4))  # 8

prices = [1.234, 2.718]
rounded = list(map(lambda price: round(price, 1), prices))
print(rounded)  # [1.2, 2.7]
```

`map(function, iterable)` applies the function to each item. In Python 3,
`map()` returns an iterator, so use `list(map(...))` when a list is required.
`round(value, digits)` rounds to the specified number of decimal places.

Add matching elements from two lists:

```python
first = [1, 2]
second = [3, 4]
totals = list(map(lambda a, b: a + b, first, second))
print(totals)  # [4, 6]
```

With multiple lists, `map()` stops at the shortest list. Check the lengths if
the question requires every element to be paired.

## 7. Modules, dates, and imports

A module is a `.py` file. Put related reusable functions in it, then import
them from another file. Keep both files in the same folder for a simple
practical setup.

**`circle.py`**

```python
import math

def area_of_circle(radius):
    return math.pi * radius ** 2
```

**`main.py`**

```python
import circle

print(circle.area_of_circle(5))
```

You can import a function directly with
`from circle import area_of_circle`, then call `area_of_circle(5)`.

Current date and time in a fixed format:

```python
from datetime import datetime

def current_datetime():
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S")

print(current_datetime())
```

Format codes used above: `%Y` year, `%m` month, `%d` day, `%H` 24-hour,
`%M` minute, `%S` second.

## 8. Files and folders

File modes to remember:

| Mode | Meaning | Example |
|---|---|---|
| `"r"` | Read an existing text file | `open("notes.txt", "r")` |
| `"w"` | Write; creates or replaces the file | `open("notes.txt", "w")` |
| `"a"` | Append at the end; creates if needed | `open("notes.txt", "a")` |
| `"rb"` / `"wb"` | Read/write binary data such as an image | `open("image.jpg", "rb")` |

Prefer `with open(...)` to ensure the file is closed, including when an error
occurs:

```python
with open("notes.txt", "w", encoding="utf-8") as file:
    file.write("Python is useful.\n")

with open("notes.txt", "r", encoding="utf-8") as file:
    for line in file:
        print(line, end="")
```

Count words:

```python
with open("notes.txt", "r", encoding="utf-8") as file:
    word_count = 0
    for line in file:
        word_count += len(line.split())
print(word_count)
```

Copy a binary file:

```python
with open("image.jpg", "rb") as source:
    data = source.read()
with open("image-copy.jpg", "wb") as destination:
    destination.write(data)
```

The `os` module provides filesystem operations:

```python
import os

os.makedirs("practice_folder", exist_ok=True)
print(os.getcwd())  # current working directory
# os.rename("old.txt", "new.txt")
# os.remove("unneeded.txt")
```

**Safety:** `os.remove()` deletes a file. Try file-operation assignments in a
temporary practice folder and use test files, not personal or important files.
The notebook's relative file paths are resolved from the program's current
working directory, which may not be the notebook's folder.

## 9. Regular expressions (`re`)

Regular expressions describe text patterns. Import the module first:

```python
import re
```

| Pattern / function | Meaning | Small example |
|---|---|---|
| `\d` | A digit | `re.findall(r"\d", "A7")` → `["7"]` |
| `\d+` | One or more digits | `re.findall(r"\d+", "A12 B7")` → `["12", "7"]` |
| `[A-Z]` | One uppercase English letter | `re.search(r"[A-Z]", "Tea")` |
| `{n}` | Exactly `n` repeats | `r"\d{4}"` matches four digits |
| `\s+` | One or more whitespace characters | `re.split(r"\s+", "one two")` |
| `\b` | Word boundary | `r"\bcat\b"` matches `cat`, not `catalog` |
| `fullmatch()` | Entire string must match | `re.fullmatch(r"\d{4}", "2026")` |
| `findall()` | Returns all matches | `re.findall(r"\d+", "A12 B7")` |
| `split()` | Splits using a pattern | `re.split(r"[,; ]+", "a,b; c")` |
| `sub()` | Replaces matches | `re.sub(r"\d+", "#", "item12")` |
| `IGNORECASE` | Matches without case sensitivity | `re.findall(r"cat", "Cat", re.IGNORECASE)` |

Examples from the assignment topics:

```python
# Simple email pattern for a college domain
re.fullmatch(r"[A-Za-z0-9._%+-]+@college\.edu", "student@college.edu")

# A 10-digit number beginning with 6, 7, 8, or 9
re.fullmatch(r"[6-9]\d{9}", "9876543210")

# Five capital letters, four digits, then one capital letter
re.fullmatch(r"[A-Z]{5}\d{4}[A-Z]", "ABCDE1234F")

# Extract marks from a sentence
re.findall(r"\d+", "Maths 85, Science 90")

# Extract hashtags and mentions containing letters
re.findall(r"#[A-Za-z]+", "#Python @Tutor")
re.findall(r"@[A-Za-z]+", "#Python @Tutor")

# Detect consecutive repeated words (case-insensitive)
re.findall(r"\b(\w+)\s+\1\b", "This is is useful", flags=re.IGNORECASE)

# Split at commas, semicolons, or spaces
re.split(r"[,; ]+", "apple;orange,banana grape")

# Replace any of several whole words (case-insensitive)
words = ["spoiler", "mistake"]
pattern = r"\b(" + "|".join(map(re.escape, words)) + r")\b"
message = re.sub(pattern, "***", "That was a mistake", flags=re.IGNORECASE)
```

A format-only date pattern can accept impossible dates such as `31-02-2026`.
For a real calendar date, parse it with `datetime.strptime()` and handle
`ValueError`. Also, validate password length with `len(password) >= 8`; merely
checking that the string is non-empty does not enforce an eight-character
minimum.

## 10. Supermarket practical: complete small program

This version combines dictionaries, functions, loops, conditions, input
conversion, stock checks, a cart, discount, tax, and invoice formatting. It
adds quantities when the same product is selected more than once.

```python
products = {
    1: {"name": "Apple", "price": 10.0, "stock": 20},
    2: {"name": "Bread", "price": 35.0, "stock": 10},
    3: {"name": "Milk", "price": 28.0, "stock": 15},
}


def show_products():
    print("\nCode  Product  Price  Stock")
    for code, product in products.items():
        print(
            f"{code:<5} {product['name']:<8} "
            f"₹{product['price']:<6.2f} {product['stock']}"
        )
    print("0     Finish purchase")


def print_bill(cart):
    subtotal = 0
    print("\n--- BILL ---")
    print("Product  Qty  Amount")

    for code, quantity in cart.items():
        product = products[code]
        line_total = product["price"] * quantity
        subtotal += line_total
        print(f"{product['name']:<8} {quantity:<4} ₹{line_total:.2f}")

    discount_rate = 0.10
    tax_rate = 0.18
    discount = subtotal * discount_rate
    taxable_amount = subtotal - discount
    tax = taxable_amount * tax_rate
    grand_total = taxable_amount + tax

    print(f"Subtotal:     ₹{subtotal:.2f}")
    print(f"Discount:    -₹{discount:.2f}")
    print(f"Tax (18%):    ₹{tax:.2f}")
    print(f"Grand total:  ₹{grand_total:.2f}")


def purchase():
    cart = {}

    while True:
        show_products()

        try:
            code = int(input("Enter product code: "))
        except ValueError:
            print("Please enter a whole-number code.")
            continue

        if code == 0:
            break
        if code not in products:
            print("Product code not found.")
            continue

        try:
            quantity = int(input("Enter quantity: "))
        except ValueError:
            print("Please enter a whole-number quantity.")
            continue

        if quantity <= 0:
            print("Quantity must be greater than zero.")
            continue

        already_in_cart = cart.get(code, 0)
        if quantity > products[code]["stock"]:
            print("Not enough stock available.")
            continue

        cart[code] = already_in_cart + quantity
        products[code]["stock"] -= quantity
        print(f"Added {quantity} x {products[code]['name']}.")

    if cart:
        print_bill(cart)
    else:
        print("No items were purchased.")


purchase()
```

### How the supermarket program works

| Part | Concept | Simple way to understand it |
|---|---|---|
| `products` | Nested dictionary | Product code points to a record with name, price, and stock |
| `show_products()` | Function + dictionary loop | Prints each product from the catalogue |
| `cart` | Dictionary | Product code maps to the number of units selected |
| `while True` | Repeating menu | Continue asking until the customer enters `0` |
| `try` / `except ValueError` | Input validation | Text like `"abc"` cannot be converted to an integer, so show a helpful message |
| `cart.get(code, 0)` | Safe dictionary lookup | Get the existing cart quantity, or use `0` if it is the first purchase |
| Stock check | Condition + arithmetic | Requested quantity must not exceed remaining stock; stock is reduced after each addition |
| `subtotal += line_total` | Accumulator | Add each product's line amount to the running total |
| Discount and tax | Percentage calculation | `amount * rate` calculates the percentage amount |
| `:.2f` | Number formatting | Display money with two digits after the decimal point |

The program applies the discount before calculating tax. If an exam question
specifies a different order, minimum bill amount, or discount rule, follow
that exact requirement. This is a classroom example, not a production payment
or tax system.

### Make it one step simpler

If a full stock-and-invoice program feels difficult, build it in this order:

1. Print three hard-coded product names and prices.
2. Read one product choice and quantity.
3. Calculate `price * quantity`.
4. Put the products in a dictionary and print them with a loop.
5. Add a `while` menu so multiple products can be bought.
6. Store quantities in a cart dictionary and calculate a subtotal.
7. Add a discount, then tax, and print a formatted bill.
8. Add stock checks and invalid-input handling.

## 11. Practical exam checklist and common mistakes

- Read the whole question first. Identify the required input, calculation, and
  exact output.
- Convert `input()` before numeric calculations: `int()` or `float()`.
- Initialize a running total/count before a loop, usually to `0`.
- Check loop boundaries. `range(1, n + 1)` includes `n`; `range(1, n)` does
  not.
- Use `==` for comparison and `=` for assignment.
- Avoid dividing by zero; check the denominator first.
- Prime checks must return `False` for numbers below `2`.
- Factorial should handle `0` as `1`; negative inputs should be rejected.
- Use `return` for values a function should give back; use `print()` for
  display.
- Remember that list indexes start at `0`, and slices exclude the stop index.
- Before dictionary access with user input, check `key in dictionary`.
- When a product can be selected repeatedly, add to its current cart
  quantity instead of overwriting it.
- Use `with open()` for files; test rename/delete operations on disposable
  files only.
- For regex, use raw strings such as `r"\d+"`; `fullmatch()` validates the
  entire input.
- Test normal input, boundary input, and invalid input. For example, test a
  quantity of `1`, the exact remaining stock, a quantity larger than stock,
  and a non-number.
- Keep names descriptive: `subtotal`, `quantity`, `product`, `is_prime`.
  Avoid replacing built-in names such as `sum`, `list`, or `str`.

## 12. Tiny last-minute reference

```python
# Input and formatted output
name = input("Name: ")
quantity = int(input("Quantity: "))
price = float(input("Price: "))
print(f"{name}: ₹{quantity * price:.2f}")

# Loop
for number in range(1, 6):
    print(number)

# Function
def multiply(a, b):
    return a * b

# List and dictionary
items = ["Apple", "Bread"]
cart = {"Apple": 2}

# String slicing
text = "Python"
print(text[::-1])  # nohtyP

# File
with open("notes.txt", "r", encoding="utf-8") as file:
    content = file.read()

# Regex
import re
is_four_digits = re.fullmatch(r"\d{4}", "2026") is not None
```
