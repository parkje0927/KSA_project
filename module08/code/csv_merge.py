import csv
import glob

# train, test, val
path = "C:/Users/user/Desktop/모듈8데이터(SSD_앵무새)/val_csv/"
merge_path = "C:/Users/user/Desktop/모듈8데이터(SSD_앵무새)/val_merge.csv"

file_list = glob.glob(path + "*")

with open(merge_path, 'w') as f:
    for i, file in enumerate(file_list):
        if i == 0:
            with open(file, 'r') as f2:
                while True:
                    line = f2.readline()

                    if not line:
                        break
                    f.write(line)

            file_name = file.split('\\')[-1]
            print(file.split('\\')[-1] + ' write complete...')

        else:
            with open(file, 'r') as f2:
                n = 0
                while True:
                    line = f2.readline()

                    if n != 0:
                        f.write(line)

                    if not line:
                        break
                    n += 1

            file_name = file.split('\\')[-1]
            print(file.split('\\')[-1] + ' write complete...')

print('>>> all fil merge complete')

