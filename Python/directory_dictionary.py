#!/usr/bin/env python

# Refer to README.md for the instructions

import os

def dir_reader(dir_path):
    
    file_dict = {}
    txt_files_path = []
    txt_file_names = []
    test_dir = dir_path.split('/')[1]
    test_dir = test_dir + '/'
    for root, dirs, files in os.walk(dir_path):
        for file in files:
            if file.endswith('.txt'):
                txt_files_path.append(root + '/' + str(file))
                txt_file_names.append(str(file))

    for i in range(len(txt_files_path)):
        with open(txt_files_path[i], 'r') as f:
            content = f.read()
            file_dict[test_dir + txt_file_names[i]] = content
    
    return file_dict
