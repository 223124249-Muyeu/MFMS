MFMS Test Log

Tester: Redemptus Muyeu (223124249), Student 7
Date: 2 October 2026

Results
- Employees: add, display, search, salary total all PASS.
  Duplicate ID accepted (FAIL). 
  Text typed for ID breaks input (FAIL).

- Menu (main.c + validation.c): all tests PASS.

- Suppliers: add, display, search all PASS.
  Duplicate ID accepted (FAIL). 
  Letters at menu reuse the previous choice (FAIL).

- Integration: suppliers.c cannot link with main.c (FAIL, both define main and displayMenu).

#Not yet tested#
Budget, assets and reports are not in the repo yet.