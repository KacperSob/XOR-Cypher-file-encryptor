# XOR Cypher File encryptor

Simple XOR Cypher File encryptor <br>

## How to install

Download git repository and use cmake and make to build.

```console
$git clone https://github.com/KacperSob/XOR-Cypher-file-encryptor
$cd XOR-Cypher-file-encryptor/build
$cmake ..
$make
```
## How to run

```
$./passwd_vault {file_to_encrypt} -e
$./passwd_vault {encrypted_file} -d {encryption.key}
```

### Usefull knowledge

Key generation is a little buggy. It is recommended to run a tests before running. <br>
Tests are disabled by default in main.c file. <br>
