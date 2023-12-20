## cs50

In this rep I put algorithms exercices from the CS50 Harvard class.

:-)

### [Class 0] Binary Search

Three search algorithms compare:

Context: search for the element "9,999,999"(findable element) and "A"(not findable element) on 10,000,000 elements array.

- Basic

  - On a present element:

    - Result 1: 9999999 (121ms)
    - Result 2: 9999999 (112ms)
    - Result 3: 9999999 (98ms)

  - On a not present element:
    - Result 1: Not found! (74ms)
    - Result 2: Not found! (62ms)
    - Result 3: Not found! (62ms)

- Double Basic

  - On a present element:

    - Result 1: 9999998 (52ms)
    - Result 2: 9999998 (53ms)
    - Result 3: 9999998 (81ms)

  - On a not present element:
    - Result 1: Not found! (43ms)
    - Result 2: Not found! (44ms)
    - Result 3: Not found! (43ms)

- Binary Search

  - On a present element:

    - Result 1: 9999998 (1ms)
    - Result 2: 9999998 (0ms)
    - Result 3: 9999998 (0ms)

  - On a not present element:
    - Result 1: Not found! (1ms)
    - Result 2: Not found! (1ms)
    - Result 3: Not found! (0ms)
