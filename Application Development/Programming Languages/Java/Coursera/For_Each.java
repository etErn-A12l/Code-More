public static String replace(String word, char gone, char here) {
    
    char[] cArray = word.toCharArray();
    char[] cArrayMod = new char[cArray.length];
    int i = 0;

    for(char c : cArray) {

        if (c == gone) 

            cArrayMod[i] = here;
        else 
            cArrayMod[i] = c;
        i++;
    }
    return new String(cArrayMod);
}

// Java regex

// Regular expression

// String apple = "I aaam happppyyyy";

// apple.split(" +");       // Splits The string without any space i.e, ['I', 'm', 'hppppyyyy']

// apple.getToken("a+")     // Returns an array of all spaces in the string i.e, ['a','a','a','a']

// String a = "Ittt it is a very bad movie it is itttt is";

// a.getToken("it*")        // The * means 0 or more i.e, this method will match any 'i' with or without a corresponding 't', i.e ['i', 'it', 'ittt']

// a.getToken("it|st")      // This method will return any match with either "it" or "st"

// a.getToken(" [123] ")    // This will search in the string individually for 1, 2 and 3

// a.getToken(" [1-3] ")    // Does the same

// a.getToken(" [a-z] ")    // Search for any characters in lowercase

// a.getToken(" [^a-z123] ")    // " ^ " means don't search any character from this set