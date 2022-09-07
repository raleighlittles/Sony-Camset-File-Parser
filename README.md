# Disclaimer: Early work-in progress

![sony alpha logo](./docs/Sony-Alpha-Logo.png)

# About

Sony cameras have the functionality to save/load special settings files --  called "Camset" (**Cam**era **Set**ings) files.

This tool is a parser for those Camset files. The goal of the project is to allow you to analyze Camset files so you can see exactly see what settings you saved with. (Eventually I'll add support for _creating_ Camset files)

# Setup/Installation

The project is a C++ application and is built via C-Make.

To build it:

```bash
$ cmake CMakeLists.txt
$ make
```

# Usage

To run:

```bash
$ sony_camset_parser <my-camset-file>
```

This will print information about your camset file:

```
Camera model is = SONYILCE-7RM4
File name is: CAMSET01.DAT
File created date: 20190712_0839
---
Image sequence prefix filename: DSC
```

# Features supported

Like I said before, this is an early work-in-progress. So far only one actual setting feature is supported.

| Menu Location | Setting Name                          | Model supported on     | Screenshots                                                                                                                                           |
|---------------|---------------------------------------|------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------|
| Setup6        | File/Folder Settings -> Set File Name | ILCE-7RM4 (Sony A7RIV) | ![ screenshot-setup-6 ]( ./docs/screenshots/setup-6_ILCE7RM4.png )  ![ File/Folder Settings ]( ./docs/screenshots/file-folder-settings_ILCE7RM4.png ) |
|               |                                       |                        |                                                                                                                                                       |
|               |                                       |                        |                                                                                                                                                       |