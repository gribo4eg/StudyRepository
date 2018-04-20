# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class KorespondentItem(scrapy.Item):
    page_url = scrapy.Field()
    page_texts = scrapy.Field()
    page_images = scrapy.Field()

class ProductItem(scrapy.Item):
    title = scrapy.Field()
    price = scrapy.Field()
    description = scrapy.Field()
    image = scrapy.Field()
