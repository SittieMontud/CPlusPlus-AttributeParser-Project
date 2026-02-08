# CPlusPlus-AttributeParser-Project
Hackerrank Problem Attribute Parser

## Input Format
The first line consists of two space separated integers,  and .  specifies the number of lines in the HRML source program.  specifies the number of queries.
The following  lines consist of either an opening tag with zero or more attributes or a closing tag. There is a space after the tag-name, attribute-name, '=' and value.There is no space after the last value. If there are no attributes there is no space after tag name.
Q queries follow. Each query consists of string that references an attribute in the source program.More formally, each query is of the form ~ where  and  are valid tags in the input.

## Constraints
Each line in the source program contains, at most,  characters.
Every reference to the attributes in the  queries contains at most  characters.
All tag names are unique and the HRML source program is logically correct, i.e. valid nesting.
A tag can may have no attributes.

## Output Format
Print the value of the attribute for each query. Print "Not Found!" without quotes if the attribute does not exist.

## Sample Input
4 3
'<tag1 value = "HelloWorld">'
'<tag2 name = "Name1">'
'</tag2>'
'</tag1>'
tag1.tag2~name
tag1~name
tag1~value

## Sample Output
Name1
Not Found!
HelloWorld
