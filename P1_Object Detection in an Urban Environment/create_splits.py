import argparse
import glob
import os
import random

import numpy as np

from utils import get_module_logger


def split(source, destination):
    """
    Create three splits from the processed records. The files should be moved to new folders in the
    same directory. This folder should be named train, val and test.

    args:
        - source [str]: source data directory, contains the processed tf records
        - destination [str]: destination data directory, contains 3 sub folders: train / val / test
    """
    # TODO: Implement function

    files = []

    for file in glob.glob(f'{source}/*.tfrecord'):
        files.append(file)

    # split data
    train_files, val_files, test_files = np.split(files, [int(.75*len(files)), int(.9*len(files))])
    
    # move data to directories
    for data in train_files:
        shutil.move(data, destination['train'])
    
    for data in val_files:
        shutil.move(data, destination['val'])
    
    for data in test_files:
        shutil.move(data, destination['test'])


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Split data into training / validation / testing')
    parser.add_argument('--source', required=True,
                        help='source data directory')
    parser.add_argument('--destination', required=True,
                        help='destination data directory')
    args = parser.parse_args()

    logger = get_module_logger(__name__)
    logger.info('Creating splits...')
    split(args.source, args.destination)