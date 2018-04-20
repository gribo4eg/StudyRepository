# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html

import os
import logging
import pprint

import xml.etree.ElementTree as ET
from lxml import etree

DIRECTORY_PATH = os.path.dirname(os.path.abspath(__file__))
KORESPONDENT_FILE = 'korrespondent.xml'
PRODUCTS_XML_FILE = 'products.xml'
PRODUCTS_XSL_FILE = 'products.xsl'

logger = logging.getLogger('logger')


class KorespondentPipeline(object):

    def __init__(self):
        self.FILE = ''.join([DIRECTORY_PATH, '/', KORESPONDENT_FILE])
        self.text_count = {}

    def open_spider(self, spider):
        tree = ET.ElementTree(ET.Element('data'))
        if os.path.exists(self.FILE):
            os.remove(self.FILE)
        tree.write(self.FILE, encoding="utf-8", xml_declaration=True)

    def process_item(self, item, spider):
        tree = ET.parse(self.FILE)
        root = tree.getroot()
        page = ET.SubElement(root, 'page', url=item['page_url'])
        for p in item['page_texts']:
            ET.SubElement(page, 'fragment', type='text').text = p
        for img in item['page_images']:
            ET.SubElement(page, 'fragment', type='image').text = img
        tree = ET.ElementTree(root)
        tree.write(self.FILE, encoding="utf-8", xml_declaration=True)

        return item

    def close_spider(self, spider):
        data = etree.parse(self.FILE)
        for sub_element in data.xpath('//page'):
            self.text_count[sub_element.xpath('./@url')[0]] = \
                len(sub_element.xpath('./fragment[@type="text"]'))
        pprint.pprint(self.text_count)


class ProductPipeline(object):

    def __init__(self):
        self.XML_FILE = ''.join([DIRECTORY_PATH, '/', PRODUCTS_XML_FILE])
        self.XSL_FILE = ''.join([DIRECTORY_PATH, '/', PRODUCTS_XSL_FILE])

    def open_spider(self, spider):
        tree = ET.ElementTree(ET.Element('items'))
        if os.path.exists(self.XML_FILE):
            os.remove(self.XML_FILE)
        tree.write(self.XML_FILE, encoding="utf-8", xml_declaration=True)

    def process_item(self, item, spider):
        tree = ET.parse(self.XML_FILE)
        root = tree.getroot()
        page = ET.SubElement(root, 'item')
        ET.SubElement(page, 'title').text = item['title']
        ET.SubElement(page, 'description').text = item['description']
        ET.SubElement(page, 'price').text = item['price']
        ET.SubElement(page, 'image').text = item['image']
        tree = ET.ElementTree(root)
        tree.write(self.XML_FILE, encoding="utf-8", xml_declaration=True)
        return item

    def close_spider(self, spider):
        dom = etree.parse(self.XML_FILE)
        xslt = etree.parse(self.XSL_FILE)
        transform = etree.XSLT(xslt)
        newdom = transform(dom)
        with open(DIRECTORY_PATH + '/products.html', 'wb') as f:
            f.write(etree.tostring(newdom, pretty_print=True))
        with open(DIRECTORY_PATH + '/products.xhtml', 'wb') as f:
            f.write(etree.tostring(newdom, pretty_print=True))
