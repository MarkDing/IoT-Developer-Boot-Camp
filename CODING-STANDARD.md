# IoT-Developer-Boot-Camp Coding Standard Guide
***
The purpose of this article is to describe the coding standing used in the IoT-Developer-Boot-Camp project. The coding standard is necessary to maintain consistency throughout the project implementation to provide a professional support to all of the users. Furthermore, adopt the coding standard increases productivity and simplifies the projects maintenance since there are lots of contributor in this project.

#### Table of Contents
[General Guidelines](#general-guidelines)
   * [General Guidelines](#general-guidelines-1)
   * [Review Committee](#review-committee)

[C Coding Standard](#c-coding-standard)
  * [General formatting](#general-formatting)
      * [Use spaces, not tabs (Required)](#use-spaces-not-tabs-required)
      * [Indents are 2 spaces per level (Required)](#indents-are-2-spaces-per-level-required)
      * [Lines should not be longer than 80 characters (Recommended)](#lines-should-not-be-longer-than-80-characters-recommended)
      * [Use only plain ASCII or UTF-8 (Required)](#use-only-plain-ascii-or-utf-8-required)
      * [Use ISO8601 formatting for dates (Required)](#use-iso8601-formatting-for-dates-required)
      * [Inserting empty and blank lines (Required)](#inserting-empty-and-blank-lines-required)
      * [Use parentheses liberally (Required)](#use-parentheses-liberally-required)
      * [Break up long expressions (Required)](#break-up-long-expressions-required)

  * [Commenting code (Required)](#commenting-code-required)
      * [Use C++ style comments ("//")](#use-c-style-comments-)

  * [Bracing style (Required)](#bracing-style-required)

  * [Switch statements](#switch-statements)
      * [Switch statements (Required)](#switch-statements-required)

  * [Functions, operators and C keywords](#functions-operators-and-c-keywords)
      * [Listing function parameters (Required)](#listing-function-parameters-required)
      * [Using function parentheses (Required)](#using-function-parentheses-required)
      * [Binary and ternary operators (Required)](#binary-and-ternary-operators-required)
      * [Use a single space after C keywords (Required)](#use-a-single-space-after-c-keywords-required)
      * [Additional space within expressions](#additional-space-within-expressions)
      * [Identify do-nothing code (Recommended)](#identify-do-nothing-code-recommended)
      * [Pointer asterisk position (Required)](#pointer-asterisk-position-required)
      * [Don't mix pointer and value type declarations (Required)](#dont-mix-pointer-and-value-type-declarations-required)

  * [Naming](#naming)
      * [Use meaningful names (Required)](#use-meaningful-names-required)
      * [Naming functions and variables](#naming-functions-and-variables)
          * [Functions and variables use camelCase (Required)](#functions-and-variables-use-camelcase-required)
          * [Functions and variables names have the form verbNoun (Required)](#functions-and-variables-names-have-the-form-verbnoun-required)
      * [Naming constants](#naming-constants)
          * [Constants should use upper case (Required)](#constants-should-use-upper-case-required)
          * [Use underscore to separate words in macros](#use-underscore-to-separate-words-in-macros)
      * [Naming types](#naming-types)
          * [Use capitalized CamelCase (Required)](#use-capitalized-camelcase-required)
              * [Public typedefs (Required)](#public-typedefs-required)
          * [Type from typedef (Optional)](#type-from-typedef-optional)
      * [Files and directory structure](#files-and-directory-structure)
          * [Filenames and directories use lower case (Required)](#filenames-and-directories-use-lower-case-required)
          * [Avoid duplicate filenames](#avoid-duplicate-filenames)
          * [Directory names (Required)](#directory-names-required)
***

## General Guidelines
### General Guidelines
We can't put everything into these guidelines, for things not covered in the guidelines, try to make your code blend in with the surrounding code you are editing. Use your best judgment!

### Review Committee
All of the pull request to merge into the master branch need to be reviewed and approved by any people in the reviewer list below, and the developers should make sure that all of the new source code implemented following the coding standard.

**Reviewers:**
[Mark.ding](https://github.com/MarkDing/IoT-Developer-Boot-Camp/commits/master/README.md?author=MarkDing)
[Jim.Lin](https://github.com/MarkDing/IoT-Developer-Boot-Camp/commits/master/README.md?author=Jim-tech)
[Eric.Su](https://github.com/MarkDing/IoT-Developer-Boot-Camp/commits/master/README.md?author=eric-silabs)
[Cheng.Yuan](https://github.com/MarkDing/IoT-Developer-Boot-Camp/commits/master/README.md?author=ChengYuan-CY)
***

## C Coding Standard
The coding standard guide details how your code should look, e.g. brace style, comment style etc. Some of the coding standard are marked as **Required** and others are **Recommended**. The **Recommended** rules should generally be followed expect some special circumstances, and the **Required** rules should always be followed.

### General formatting
#### Use spaces, not tabs (Required)
For indenting files, use spaces and never tabs. A mix of tabs and spaces is never acceptable.

#### Indents are 2 spaces per level (Required)
Indent each nested level with 2 spaces of indent.

#### Lines should not be longer than 80 characters (Recommended)
We enforce an 80 characters limit per line of source code. This lets people set up their editors such that they can have multiple editors side-by-side. Although 80 characters are little by modern standards, it mixes well with existing code.

#### Use only plain ASCII or UTF-8 (Required)
Text files should almost always contain only plain ASCII. Specifically, avoid characters outside the usual whitespace and printable ones (0x9-0xD and 0x20-0x7E, inclusive). Internationalized strings, when used, are best placed in a resource file.
In the rare case that other characters are needed in a text file and cannot be escaped, the file should be UTF-8 encoded with no byte-order mark.

#### Use ISO8601 formatting for dates (Required)
If you use a date in the comments or elsewhere, specify it using the unambiguous ISO8601 format, i.e. 2019-10-10.

#### Inserting empty and blank lines (Required)
There should never be consecutive blank rows.
Use two slashes (C++ comment) and 77 dashes to separate logical parts of the code. Use 2 slashes and 32 dashes for minor sections. Use of section separators as shown here is optional.
Example
```
// -----------------------------------------------------------------------------
// Here we start a new logical part in this source/header file...

// -------------------------------
// And here comes a new minor section...
```
#### Use parentheses liberally (Required)
Add parentheses if you have any doubt at all about precedence, not doing so has led to some very obscure bugs. This is especially true of the bitwise binary operators {&, |, ^} and Boolean operators {&&, ||}.

#### Break up long expressions (Required)
Whenever there are long expressions, it should be broken into multiple lines. When a line is broken into multiple lines, each line should start with the operator that operates on that full line (single element or a group of elements within parentheses). The operator must be the first thing on the line, and it should be indented appropriately.
Example
```
int bitmask = (OPTION_1
               | OPTION_2
               | (IS_THIS_SET
                  ? OPTION_3
                  : OPTION_4));

int bitmask = (OPTION_1
               | OPTION_2
               | (IS_THIS_SET ? OPTION_3 : OPTION_4));

int bitmask = (OPTION_1
               | OPTION_2
               | (OPTION_3 & OPTION_4));
```
**Comment**: All the above are examples of nicely formatted long expressions.
Below is an example how you should not format long and complex expressions.
```
// Avoid this...
int no-good-formatting = (OPTION_1
                         | OPTION_2
                         | OPTION_3 & OPTION_4);
```

### Commenting code (Required)
#### Use C++ style comments ("//")
All inline code comments should use the C++ style //. However there are two exceptions to this rule. 
First, function and file documentation blocks use a different style (see documentation section below).
Second, for multi-line macros using #define, C style comments /* ... */ should be used for embedded comments (see example below).
For both kinds of comments, there should be a space following the opening comment marker. For example // My comment.
Make sure constant values in the code are explained. Function calls with raw constants should be labeled based on the parameter that is being passed in.
Example
```
// Example for the exception
// This type is needed because using // would swallow the line continuation marker.
#define MY_CLI_COMMANDS \
  /* This command takes 3 arguments: */           \
  /*  Node ID - a 2-byte node ID destination */   \
  /*  Endpoint - a 1-byte node ID */              \
  /*  Cluster  - a 2-byte cluster ID */           \
  { "my_command", myCommandFunction, "vuv" },

// Example of how to comment constant values.
// For the function declaration below
void function(int seconds, boolean printOutput);

// we add comments after each parameter (OPTIONAL)
function(0,        // seconds
         FALSE);   // printOutput
```

### Bracing style (Required)
Use the so called ["One True Brace Style"](https://en.wikipedia.org/wiki/Indent_style#Variant:_1TBS) Indent increases one level after an opening brace, and decreases one level before a closing brace. Opening braces do not go on their own separate line, except for free standing blocks and function definitions. Closing braces are on their own separate line with nothing else on these lines.
All if/else blocks must be enclosed by braces, even if there is only one statement in the conditional.
Exceptions for the above rule are;
	1. The typedef alias for a composite (struct/union) or enum type is on the same line as the closing brace.
	2. In a do-while loop the condition ( while (...); ) is on the same line as the closing brace.
	3. else and else if are on the same line as the closing brace.
Example
```
void foo(uint8_t bar)
{
  if (foo > bar) { // The preceding brace is *required*
    doThis();
  } else {
    doAnotherThing();
  }

  if (foo > bar) {
    doThis();
  }

  do {
    doWork();
  } while (foo);
}

typedef enum {
  SPADE,
  HEART,
  CLUB,
  DIAMOND
} CardSuit_t;
```

### Switch statements
#### Switch statements (Required)
The cases in switch statements should be indented one level from the enclosing braces. Separate case blocks with a blank line after each break;. All switch statements should include a default block unless there is a good reason not to. The default block can collapse into one of the other cases but it should clearly show what happens when there is no matching case. Finally, if a case block does not end with an unconditional jump, there should be a comment clearly stating that the code is intentionally meant to fall through.
Example
```
switch(baz) {
  case 1:
    doThis();
    break;

  case 2:
    doThat();
    // This case is meant to fall through to the next

  case 3: {
    doTheOtherThing();
    break;
  }

  case 0:
  default:
    doWhat();
    break;
}
```

### Functions, operators and C keywords
#### Listing function parameters (Required)
Whenever there is a list of function parameters, they should all fit on a single line or be listed one parameter per line. If listed on separate lines, each parameter has the same indent level as the first parameter.
Example
```
void myFunction(int a,
                int b,
                int c,
                const char *string1,
                const char *string2)
{
  // ...
}

void myFunction2(int a, int b, int c)
{
  // ...
}
```

#### Using function parentheses (Required)
For function declarations, definitions and calls, there shall be no spaces before or after the opening parentheses, or before the closing parentheses.
Example
```
int foo(int days, int seconds);
// ...
ret = foo(days, seconds);
```

#### Binary and ternary operators (Required)
Use spaces around binary & ternary operators in expressions. C expressions are hard enough to parse without running them altogether.
Example
```
for (j = 0; j < parameterSizes[i]; j++) {
```

#### Use a single space after C keywords (Required)
C keywords (ex. for, switch, while, if, do) – should have a single space after the keyword.
Example
```
while (counter < UART_MAX_IO_BUFFER) {
```

#### Additional space within expressions
Use of additional whitespace within expressions to improve readability is permitted as long as it doesn't interfere with appropriate multi-line expression indentation. Such style should be consistent within the module.

#### Identify do-nothing code (Recommended)
Avoid loops that do not make it obvious that they do nothing. Add a comment to explain the reason for the do-nothing loop. This applies to any code that does not do anything.
Example
```
// Don't do:
while (waiting_for_something);

// Instead do:
// Useful comment explaining why you are waiting
while (waiting_for_something);
```

#### Pointer asterisk position (Required)
When declaring a pointer to a variable, the pointer asterisk should be placed together with the variable name, not together with the type.
Example
```
// Don't do:
char* c = (char*)a;
void foo(uint32_t* bar);

// Instead do:
char *c = (char *)a;
void foo(uint32_t *bar);
```

#### Don't mix pointer and value type declarations (Required)
Don't mix declarations of pointer type variables and value type variables on the same line.
Example
```
// Don't do:
uint32_t *a, b;

// Instead do:
uint32_t *a;
uint32_t b;
```

### Naming
#### Use meaningful names (Required)
Special care should be taken when creating new functions. The name should convey the purpose of the function as clearly as possible.

#### Naming functions and variables
##### Functions and variables use camelCase (Required)
Function names should be in camelCase with the first letter lowercase.
Example
```
void radioTrasmit();
```

##### Functions and variables names have the form verbNoun (Required)
When a verb and a noun the verb acts on are in a function name, the verb should come first (getPower, not powerGet). It should feel natural to read the name.
Variables and functions of boolean type should use a naming style indicating the sense of the boolean. For example isConnected.
Example
```
// This is for legacy EM code and does not apply to 8051
// code base.

getPower();    // Call to a new-style API function.

// Below is an example of how to redefine old style API calls to the new syntax.
#if (SLAB_OLD_API == SLAB_REPLACE_OLD_API_CALLS)
#define powerGet getPower
#define powerSet setPower
#endif
```

#### Naming constants
##### Constants should use upper case (Required)
All constants should be named and use upper case letters. Avoid raw numbers in code.

##### Use underscore to separate words in macros
To separate words in a constant use underscore ('_') between words (see example).
Example
```
#define SLAB_WEDNESDAY       4
```

#### Naming types
##### Use capitalized CamelCase (Required)
All types use CamelCase with the first letter uppercase.

###### Public typedefs (Required)
Each typedef must end with a '_t' suffix and cannot start with 'int', 'uint' or 'unicode'.

##### Type from typedef (Optional)
If the type is a typedef, you can optionally add a type name if there is a reason the anonymous type does not work. In this case use the same name as the typedef name, without the '_t'.
Example
```
// Anonymous structure name ...
// Use this style in most cases.
typedef struct
{
  // ...
} NvmPageHeader_t;

// You can use this style if the struct needs a name.
typedef struct NvmPageHeader
{
  // ...
} NvmPageHeader_t;
```

#### Files and directory structure
##### Filenames and directories use lower case (Required)
All file names are lower case and multiple words are separated with one underscore '_'.
Example
```
packet_buffer.c
```

##### Avoid duplicate filenames
Avoid using the same file name for source files.
Note: Among our entire source code there will be files with the same name. This cannot be avoided. But files with the same name should never be used in the same project/build.

##### Directory names (Required)
Directories use lower case names and underscores as word separators.
***
## Reversion Information
**Revision 1.0**
   * 2019-09-26
   * Initial Revision