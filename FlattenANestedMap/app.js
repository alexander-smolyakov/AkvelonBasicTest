// Link on task -> https://www.codewars.com/kata/52859abdf8fc1b12e0000141/

'use strict';

function GenerateNestedMap (obj, root, map) {
    Object.keys(obj).forEach(key => {
        var route = root === '' ? key : root + '/' + key;
        if (typeof obj[key] === 'object' && !Array.isArray(obj[key]) && obj[key]) {
            map = GenerateNestedMap(obj[key], route, map);
        } else { 
            map[route] = obj[key];
        }
    })
    return map;
}

function flattenMap(map) {
    var nestedMap = {};
    nestedMap = GenerateNestedMap(map, '', nestedMap)
    return nestedMap;
}

function consoleLog(case_namuber, expected_result, result) {
    console.log(`Case ${case_namuber} = ${JSON.stringify(expected_result) === JSON.stringify(result)? 'passed' : 'error'}`);
}

// Test case from Codewars
var input = {
    'a': {
        'b': {
            'c': 12,
            'd': 'Hello World'
        },
        'e': [1, 2, 3]
    }
};

var result = flattenMap({ "a": null });
var expected_result = {
    'a/b/c': 12,
    'a/b/d': 'Hello World',
    'a/e': [1, 2, 3]
};

consoleLog(1, expected_result, result);

