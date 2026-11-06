function func(str, subStr) {
    // Base case: no characters left
    if (str.length === 0) {
        console.log(subStr);
        return;
    }

    // Pick each character one by one
    for (let i = 0; i < str.length; i++) {

        // Remove the i-th character
        let remaining = str.slice(0, i) + str.slice(i + 1);

        // Recurse
        func(remaining, subStr + str[i]);
    }
}

// Initial call
let str = "ABC";
func(str, "");
