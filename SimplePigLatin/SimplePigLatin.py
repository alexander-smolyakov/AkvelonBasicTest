#Link on task -> https://www.codewars.com/kata/520b9d2ad5c005041100000f

def pig_it(string):
    letter_filter = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789"
    string = string.split(" ")
    new = []
    
    for i in range(len(string)):
        if string[i] in letter_filter and len(string[i]) == 1:
            string[i] = string[i]+ "ay"
            
        elif len(string[i]) >= 2:
            string[i] = string[i][1: -1]+ string[i][-1]+  string[i][0]+ "ay"
        
        else: string[i] = string[i]
        new.append(string[i])
        
    return " ".join(new)

#Test cases from Codewars
print(pig_it('Pig latin is cool') == 'igPay atinlay siay oolcay')
print(pig_it('This is my string') == 'hisTay siay ymay tringsay')
