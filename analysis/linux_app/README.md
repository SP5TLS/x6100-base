# Reproducing the Linux hardware audit

Source ELF:

`x6100_ui_v100`

Expected hashes:

```text
MD5     9017e6c2175dccb432b0ba3d84f480db
SHA-256 f0f154b754b2d68a448a5e06dde4a040e57fd2b1c1d305d64b470e4aaf98d427
```

The initial symbol and string index can be regenerated with:

```sh
nm -C -n x6100_ui_v100
strings -a -t x x6100_ui_v100
readelf -h -S -Ws x6100_ui_v100
```

Import the ELF into a separate Ghidra project, then use the repository
scripts `ExportCallGraph.java`, `ExportDecompiledFunctions.java`, and
`ExportFunctionsByAddress.java`. The primary function entry points are:

```text
0006E704 MorseSender::slot_worker
0006F784 uart_create
0006FB78 _comm_send_cmd
0006FEC4 XMWorker::slot_start
00070FBC UiFwUpgrade::upgradeFirmware
00072414 ui2c_write
0007269C ui2c_read
00072890 ui2c_create
0007A5B4 Xmodem::crc16
0007A64C Xmodem::sendPacket_1k
0007A6D4 Xmodem::waitRespond
0007A75C Xmodem::sendFile
0008F9D0 thread_remote_admin
0009292C xradio_create
000933EC xradio_start_xmodem
```

At the `xradio_create` call site `0x000649E0`, register `r1` is loaded
with `0x72`. The PC-relative `r0` literal resolves to ELF virtual
address `0x000D92AD`, the string `/dev/i2c-0`: VERIFIED.

Inside `xradio_create`, the PC-relative UART-path literal resolves to
virtual address `0x000DD533`, the string `/dev/ttyS1`, and the speed
argument is `0x1009`: VERIFIED.

Do not preserve OEM decompiler output in this repository. The CSV files
in this directory contain only independently useful interface facts and
evidence locations.
