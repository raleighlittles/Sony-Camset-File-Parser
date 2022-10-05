# Unknown bytes from diff between single and continous shooting mode

The continous shooting mode and single shooting mode had bytes that differed in several locations:

* Byte index: 0x170, 364d
* Byte index: 0x5A9, 1449d


To show these, add sample:

```rust

    println!("-" * 10);

        // 0x170 byte index
        let unknown_byte_1 = &camset_file_as_bytes[364];

        // 0x5A9 byte index
        let unknown_byte_2 = &camset_file_as_bytes[1449];
    
        println!("Byte 0x170 (Unknown 1): {}", unknown_byte_1);
        println!("Byte 0x5A9 (Unknown 2): {}", unknown_byte_2);
```

Plus more bytes:

```
00002000: e9f9 b8fa 7bfe f9fe f3ff f7ff f7ff c0ff  ....{..... | 
00002010: 5bff f4ff f7ff dfff eeff d9ff f6ff f4ff  [......... | 
00002050: fbff d2ff eeff 2bfc faff f9ff f7ff f5ff  ......+... |
```

```
00002000: e9f9 7bfa 7bfe f9fe f3ff f7ff f7ff c0ff  ..{.{.....
00002010: 5bff f4ff f7ff e0ff eeff d9ff f6ff f4ff  [.........
00002050: fbff d2ff eeff 2bfc faff faff f7ff f5ff  ......+...
```

![screenshot of diff](./docs/Screenshotfrom2022-10-04-22-24-44.png)