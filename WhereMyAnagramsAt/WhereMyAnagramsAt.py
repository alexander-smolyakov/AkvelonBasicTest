#Link on task -> https://www.codewars.com/kata/523a86aa4230ebb5420001e1/
def anagrams(word, listOfWords):
    isMatch = sorted(word);
    return [w for w in listOfWords if isMatch == sorted(w)];

#Test cases from Codewars
print(anagrams('abba', ['aabb', 'abcd', 'bbaa', 'dada']) == ['aabb', 'bbaa']);
print(anagrams('racer', ['crazer', 'carer', 'racar', 'caers', 'racer']) == ['carer', 'racer']);