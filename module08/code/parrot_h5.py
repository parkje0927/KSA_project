# 데이터set을 만드는 부분
from data_generator.object_detection_2d_data_generator import DataGenerator

# 1: Instantiate two `DataGenerator` objects: One for training, one for validation.

# Optional: If you have enough memory, consider loading the images into memory for the reasons explained above.

train_dataset = DataGenerator(load_images_into_memory=False, hdf5_dataset_path=None)
val_dataset = DataGenerator(load_images_into_memory=False, hdf5_dataset_path=None)
test_dataset = DataGenerator(load_images_into_memory=False, hdf5_dataset_path=None)

# 2: Parse the image and label lists for the training and validation datasets.

# TODO: Set the paths to your dataset here.

# Images
images_dir = './image_merge'

# Ground truth
train_labels_filename = 'C:/Users/user/Desktop/모듈8데이터(SSD_앵무새)/train_merge.csv'
val_labels_filename = 'C:/Users/user/Desktop/모듈8데이터(SSD_앵무새)/val_merge.csv'
test_labels_filename = 'C:/Users/user/Desktop/모듈8데이터(SSD_앵무새)/test_merge.csv'

train_dataset.parse_csv(images_dir=images_dir,
                        labels_filename=train_labels_filename,
                        input_format=['image_name', 'xmin', 'xmax', 'ymin', 'ymax', 'class_id'],
                        include_classes='all')

val_dataset.parse_csv(images_dir=images_dir,
                      labels_filename=val_labels_filename,
                      input_format=['image_name', 'xmin', 'xmax', 'ymin', 'ymax', 'class_id'],
                      include_classes='all')

test_dataset.parse_csv(images_dir=images_dir,
                      labels_filename=test_labels_filename,
                      input_format=['image_name', 'xmin', 'xmax', 'ymin', 'ymax', 'class_id'],
                      include_classes='all')

train_dataset.create_hdf5_dataset(file_path='parrot_train.h5',
                                  resize=False,
                                  variable_image_size=True,
                                  verbose=True)

val_dataset.create_hdf5_dataset(file_path='parrot_val.h5',
                                resize=False,
                                variable_image_size=True,
                                verbose=True)

test_dataset.create_hdf5_dataset(file_path='parrot_test.h5',
                                resize=False,
                                variable_image_size=True,
                                verbose=True)

# Get the number of samples in the training and validations datasets.
train_dataset_size = train_dataset.get_dataset_size()
val_dataset_size = val_dataset.get_dataset_size()
test_dataset_size = test_dataset.get_dataset_size()

print("Number of images in the training dataset:\t{:>6}".format(train_dataset_size))
print("Number of images in the validation dataset:\t{:>6}".format(val_dataset_size))
print("Number of images in the test dataset:\t{:>6}".format(test_dataset_size))

train_dataset = DataGenerator(load_images_into_memory=False, hdf5_dataset_path='./parrot_train.h5')
val_dataset = DataGenerator(load_images_into_memory=False, hdf5_dataset_path='./parrot_val.h5')
test_dataset = DataGenerator(load_images_into_memory=False, hdf5_dataset_path='./parrot_test.h5')
