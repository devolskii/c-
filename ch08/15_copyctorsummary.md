# Copy Constructor Summary

|IF YOU DEFINE . . . . . .|THEN THE COMPILER GENERATES . . .|. . . AND YOU CAN CREATE AN OBJECT . . .|
|---|---|---|
|[no constructors]|A default constructor <br> <br> A copy constructor|With no arguments: <br>`SpreadsheetCell cell;` <br>As a copy of another object: <br>`SpreadsheetCell myCell(cell);`|
|A default constructor only|A copy constructor|With no arguments: <br>`SpreadsheetCell cell;` <br>As a copy of another object: <br>`SpreadsheetCell myCell(cell);`|
|A copy constructor only |No constructors|Theoretically, as a copy of another object. Practically, you can’t create any objects, because there are no non-copy constructors.|
|A single-argument or multi-argument non-copy constructor only|A copy constructor|With arguments:<br>`SpreadsheetCell cell(6)`;<br>As a copy of another object:<br>`SpreadsheetCell myCell (cell);`|
|A default constructor as well as a singleargument or multiargument non-copy constructor|A copy constructor|With no arguments:<br>`SpreadsheetCell cell;`<br>With arguments:<br>`SpreadsheetCell myCell(5);`<br>As a copy of another object:<br>`SpreadsheetCell anotherCell(cell);`|
