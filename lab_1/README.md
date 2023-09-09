# Lab 1

## Usage

### CLI with CLI11 Lib

CLI has the next commands:

```cpp
$ ./lab_1 --help
lab_1
Usage: ./lab_1 [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit

Subcommands:
  add-user                    Add user
  add-worker                  Add worker
  add-book                    Add book
  remove-user                 Remove user
  remove-worker               Remove worker
  remove-book                 Remove book
  borrow-book                 Borrow book
  return-book                 Return book
  show-users                  Shows users
  show-workers                Shows workers
  show-books                  Shows books
  show-user-books             Shows user-books

```

Command arguments

```cpp
$ ./lab_1 --help
Add user
Usage: ./lab_1 add-user [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -i,--id REQUIRED            User's id
  -n,--name REQUIRED          User's name
  -m,--middle-name REQUIRED   User's middle name
  -s,--surname REQUIRED       User's surname
  -g,--gender :value in {Female->1,Male->0} OR {1,0} REQUIRED
                              User's gender
  -r,--residence REQUIRED     User's residence
  -a,--age REQUIRED           User's age
  --passport-data REQUIRED    User's passport data
```

### Examples

```cpp
$ ./lab_1 add-worker -i 0 -n Serhii -m Vitaliyovich -s Panchenko -g Male -r Kyiv -a 19 --passport-data xxxxxxxx --position-id 0
$ ./lab_1 add-worker -i 1 -n Homer -m Abe -s Simpson -g Male -r Springfield -a 40 --passport-data xxxxxxxx --position-id 1
$ ./lab_1 show-workers
Id: 0,  Name: Serhii,   MiddleName: Vitaliyovich,       Surname: Panchenko,     Gender: Male,   Residence: Kyiv,        Age: 19,        PassportData: xxxxxxxx,         PositionId: 0, 
Id: 1,  Name: Homer,    MiddleName: Abe,        Surname: Simpson,       Gender: Male,   Residence: Springfield,         Age: 40,        PassportData: xxxxxxxx,         PositionId: 1,
$ ./lab_1 add-book -i 0 -t "The C++ Programming Language"
$ ./lab_1 add-book -i 1 -t "Modern C++"
$ ./lab_1 add-book -i 2 -t "C++ Templates: The Complete Guide"
$ ./lab_1 show-books
Id: 0,  Title: The C++ Programming Language, 
Id: 1,  Title: Modern C++, 
Id: 2,  Title: C++ Templates: The Complete Guide,
$ ./lab_1 add-user -i 0 -n Bjarne -m None -s Stroustrup -g Male -r Aarhus -a 72 --passport-data DENMARK_MD
$ ./lab_1 add-user -i 1 -n Nicolai -m M. -s Josuttis -g Male -r Berlin -a 61 --passport-data DEUSTCHLAND_MD
$ ./lab_1 show-users
Id: 0,  Name: Bjarne,   MiddleName: None,       Surname: Stroustrup,    Gender: Male,   Residence: Aarhus,      Age: 72,        PassportData: DENMARK_MD, 
Id: 1,  Name: Nicolai,  MiddleName: M.,         Surname: Josuttis,      Gender: Male,   Residence: Berlin,      Age: 61,        PassportData: DEUSTCHLAND_MD,
$ ./lab_1 borrow-book -u 0 -b 0
$ ./lab_1 borrow-book -u 1 -b 2
$ ./lab_1 show-user-books
UserId: 0,      BookId: 0, 
UserId: 1,      BookId: 2,
$ ./lab_1 remove-user -i 1
Foreign reference to Id (1) exists
$ ./lab_1 return-book -u 1 -b 2
$ ./lab_1 show-user-books
UserId: 0,      BookId: 0,
$ ./lab_1 remove-user -i 1
$ ./lab_1 show-users
Id: 0,  Name: Bjarne,   MiddleName: None,       Surname: Stroustrup,    Gender: Male,   Residence: Aarhus,      Age: 72,        PassportData: DENMARK_MD,


```
