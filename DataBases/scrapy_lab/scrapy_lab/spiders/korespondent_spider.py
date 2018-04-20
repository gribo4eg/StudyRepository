import scrapy
from scrapy_lab.items import KorespondentItem


class KorespondentSpider(scrapy.Spider):
    name = 'korespondent'

    custom_settings = {
        'ITEM_PIPELINES': {
            'scrapy_lab.pipelines.KorespondentPipeline':300
        }
    }

    start_urls = [
        'https://korrespondent.net/tech/',
        #'http://news.bigmir.net/'
    ]

    #korespondent
    def parse(self, response):
        for a in response.xpath('//div[@class="article__title"]/a/@href'):
            yield response.follow(a, callback=self.parse_item)

    #bigmir
    # def parse(self, response):
    #     for pos, a in enumerate(
    #             response.xpath('//a[@class="b-last-news-feed__list-item__title"]/@href')):
    #         if pos is 20: break
    #         pos += 1
    #         yield response.follow(a, callback=self.parse_item)


    def parse_item(self, response):

        def extract_all_xpath(query):
            return response.xpath(query).extract()

        texts = []
        for text in extract_all_xpath('//p/text()'):
            text = text.rstrip()
            if len(text) is not 0:
                texts.append(text)

        yield KorespondentItem(
            page_url = response.request.url,
            page_texts = texts,
            page_images = extract_all_xpath('//img/@src')
        )