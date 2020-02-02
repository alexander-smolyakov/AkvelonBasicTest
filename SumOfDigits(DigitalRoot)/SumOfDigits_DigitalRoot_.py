def digital_root(n):
     digits = map(int, str(n));
     sumOfDigit = sum(digits);

     if(sumOfDigit > 10): return digital_root(sumOfDigit);
     else : return sumOfDigit;
 
print(digital_root(16) == 7);
print(digital_root(456) == 6);
