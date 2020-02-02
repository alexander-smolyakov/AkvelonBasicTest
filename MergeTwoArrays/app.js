// Link on task -> https://www.codewars.com/kata/583af10620dda4da270000c5/solutions/javascript

'use strict';

function mergeArrays(a, b) {
    let mergedArray = [];

    if (a.length > b.length) {
        let i = 0;
        for (; i < b.length; i++) {
            mergedArray.push(a[i]);
            mergedArray.push(b[i]);
        }
        for (; i < a.length; i++) {
            mergedArray.push(a[i]);
        }
    } else {
        let i = 0;
        for (; i < a.length; i++) {
            mergedArray.push(a[i]);
            mergedArray.push(b[i]);
        }
        for (; i < b.length; i++) {
            mergedArray.push(b[i]);
        }
    }

    return mergedArray;
}

var arraysMatch = function (arr1, arr2) {
    if (arr1.length !== arr2.length) return false;

    for (var i = 0; i < arr1.length; i++) {
        if (arr1[i] !== arr2[i]) return false;
    }

    return true;
};

function consoleLog(case_namuber, expected_result, result) {
    console.log(`Case ${case_namuber} = ${arraysMatch(expected_result, result) ? 'passed' : 'error'}`);
}

// Test cases from Codewars
var expected_result = [1, "a", 2, "b", 3, "c", 4, "d", 5, "e", 6, 7, 8];
var result = mergeArrays([1, 2, 3, 4, 5, 6, 7, 8], ['a', 'b', 'c', 'd', 'e']);
consoleLog(1, expected_result, result);

expected_result = ['a', 1, 'b', 2, 'c', 3, 'd', 4, 'e', 5];
result = mergeArrays(['a', 'b', 'c', 'd', 'e'], [1, 2, 3, 4, 5]);
consoleLog(2, expected_result, result);

expected_result = [2, 'b', 5, 'r', 8, 'a', 23, 'u', 67, 'r', 6, 's']
result = mergeArrays([2, 5, 8, 23, 67, 6], ['b', 'r', 'a', 'u', 'r', 's']);
consoleLog(3, expected_result, result);

expected_result = ['b', 2, 'r', 5, 'a', 8, 'u', 23, 'r', 67, 's', 6, 'e', 'q', 'z']
result = mergeArrays(['b', 'r', 'a', 'u', 'r', 's', 'e', 'q', 'z'], [2, 5, 8, 23, 67, 6]);
consoleLog(4, expected_result, result);
