import scrapy
from scrapy_lab.items import ProductItem


class ProductsSpider(scrapy.Spider):
    name = 'products'

    custom_settings = {
        'ITEM_PIPELINES': {
            'scrapy_lab.pipelines.ProductPipeline':300
        }
    }

    start_urls = [
        'https://hotline.ua/musical_instruments/elektrogitary/'
    ]

    def parse(self, response):
        for a in response.xpath('//div[@class="item-info"]//p[@class="h4"]/a/@href'):
            yield response.follow(a, callback=self.parse_item)

    def parse_item(self, response):

        def extract_first_xpath(query):
            return response.xpath(query).extract_first()

        yield ProductItem(
            title = extract_first_xpath('//div[@class="heading"]/h1[@datatype="card-title"]/text()').strip(),
            price = extract_first_xpath('//div[@class="cell-12"]//span[@class="value"]/text()').replace('\xa0',''),
            description = extract_first_xpath('//div[@class="text"]/p/text()').strip(),
            image = extract_first_xpath('//div[@class="cell-list"]//img[@class="img-product busy"]/@src')
        )