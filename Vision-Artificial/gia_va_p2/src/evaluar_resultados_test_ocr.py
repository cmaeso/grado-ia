import csv
import matplotlib.pyplot as plt
import numpy as np
import argparse


def read_csv_file(file, delim=";"):
    """

    """
    panels_info = dict()
    with open(file) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=delim)
        line_count = 0
        for row in csv_reader:
            #print(row)
            image_name = row[0]
            try:
                panel_text = row[5]
            except:
                panel_text = "" # The OCR could fail in this image
            if panels_info.get(image_name) is None:
                panels_info[image_name] = [panel_text]
            else:
                print('image=', image_name)
                l = panels_info[image_name]
                l.append([panel_text])
                panels_info[image_name] = l

            line_count += 1
    return panels_info


def levenshtein_distance(str1, str2):
    """
    https://ast.wikipedia.org/wiki/Distancia_de_Levenshtein
    """
    d = dict()
    for i in range(len(str1) + 1):
        d[i] = dict()
        d[i][0] = i
    for i in range(len(str2) + 1):
        d[0][i] = i
    for i in range(1, len(str1) + 1):
        for j in range(1, len(str2) + 1):
            d[i][j] = min(d[i][j - 1] + 1, d[i - 1][j] + 1, d[i - 1][j - 1] + (not str1[i - 1] == str2[j - 1]))

    return d[len(str1)][len(str2)]


def plot_recognition_distance(p_gt, p):
    """
    """
    txt_distance_all = []
    for img_name in p_gt:
        p_info_gt = p_gt[img_name]

        if p.get(img_name) is None:  # Not found a word in this image.
            txt_distance_all.append(-1) # -1 is not found text
            continue

        p_info = p[img_name]

        # By now we assume only one detection for each image
        plate_gt = p_info_gt[0]
        if len(p_info) >= 1:  # if we have at least one detection
            plate = p_info[0]

            txt_distance = levenshtein_distance(plate_gt, plate)
            txt_distance_all.append(txt_distance)

    print(txt_distance_all)

    # Plot histogram
    plt.figure()
    #hist, bin_edges = np.histogram(np.array(txt_distance_all),  bins=8, density=False)
    #plt.step(bin_edges[:-1], hist, where='mid')
    plt.hist(np.array(txt_distance_all))
    plt.title("Distancia de Levenshtein: texto reconocido vs real")
    plt.ylabel("Núm. imágenes")
    plt.xlabel('Distancia de edición (en "número de operaciones")')
    plt.show()
#    print("hist=", hist)
#    print("bin_edges=", bin_edges)
#    print(hist[0:5].sum())

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='Calcula distancias de Levenshtein para un OCR')
    parser.add_argument(
        '--ocr_gt_file', default="./test_ocr_words_plain/gt.txt", help='Fichero con palabras reales (ground truth)')
    parser.add_argument(
        '--ocr_estimated_file', default="./results_ocr_words_plain/results_text_lines.txt", help='Fichero con palabras estimadas por el OCR')
    args = parser.parse_args()

    words_gt = read_csv_file(args.ocr_gt_file)
    print(words_gt)

    words_estimated = read_csv_file(args.ocr_estimated_file)
    print(words_estimated)

    plot_recognition_distance(words_gt, words_estimated)
