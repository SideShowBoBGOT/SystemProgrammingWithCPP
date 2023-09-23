./main.out add-worker -i 0 -n Serhii -m Vitaliyovich -s Panchenko -g Male -r Kyiv -a 19 --passport-data xxxxxxxx --position-id 0
./main.out add-worker -i 1 -n Homer -m Abe -s Simpson -g Male -r Springfield -a 40 --passport-data xxxxxxxx --position-id 1
./main.out show-workers
./main.out add-book -i 0 -t "The C++ Programming Language"
./main.out add-book -i 1 -t "Modern C++"
./main.out add-book -i 2 -t "C++ Templates: The Complete Guide"
./main.out show-books
./main.out add-user -i 0 -n Bjarne -m None -s Stroustrup -g Male -r Aarhus -a 72 --passport-data DENMARK_MD
./main.out add-user -i 1 -n Nicolai -m M. -s Josuttis -g Male -r Berlin -a 61 --passport-data DEUSTCHLAND_MD
./main.out show-users
./main.out borrow-book -u 0 -b 0
./main.out borrow-book -u 1 -b 2
./main.out show-user-booksh