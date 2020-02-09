#Linkon task -> https://www.codewars.com/kata/5b1b27c8f60e99a467000041

def anagram_difference(first_word, second_word):
    length = len(first_word) + len(second_word)
    count = 0
    for letter in first_word:
        if letter in second_word:
            count += 1
            second_word = second_word.replace(letter, '', 1)
    return length - 2*count

test_cases = (
    ('', '', 0),
    ('a', '', 1),
    ('', 'a', 1),
    ('ab', 'a', 1),
    ('ab', 'ba', 0),
    ('ab', 'cd', 4),
    ('codewars', 'hackerrank', 10)
)

for first_word, second_word, expected in test_cases:
    result = anagram_difference(first_word, second_word);
    print(f'Test: Words ({first_word},{second_word}). Expected: {expected}. Get: {result}. -> ', result == expected)