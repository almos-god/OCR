import sys
from paddleocr import PaddleOCR

def ocr_image(image_path):
    ocr = PaddleOCR(use_angle_cls=True, lang='ch')
    result = ocr.ocr(image_path, cls=True)
    text = ""
    for line in result:
        for word_info in line:
            text += word_info[-1][0] + " "  # 提取每一行的文本
        text += "\n"
    return text.strip()

if __name__ == "__main__":
    #if len(sys.argv) < 2:
    #    print("Usage: python PaddleOCR.py <image_path>")
    #    sys.exit(1)

    image_path ="C:\Desktop\aa (2).png"# sys.argv[1]
    result = ocr_image(image_path)
    print(result)  # 输出 OCR 结果
