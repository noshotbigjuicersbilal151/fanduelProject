import requests
from bs4 import BeautifulSoup
import re
import os
os.environ['OPENBLAS_NUM_THREADS'] = '1'
import pandas as pd
import csv

month = input("Enter month: ")
day = input("Enter day: ")
year = input("Enter year: ")

pointGuards = []
strings = []

URL = "http://rotoguru1.com/cgi-bin/hyday.pl?game=fd&mon=" + month + "&day=" + day + "&year=" + year + "&scsv="
page = requests.get(URL)
soup = BeautifulSoup(page.content, "html.parser")

pointGuards = soup.find_all('table')
myTable = pointGuards[8]
list_of_rows = []
for row in myTable.findAll('tr'):
    list_of_cells = []
    for cell in row.findAll(["td"]):
        text = cell.text
        if text.find('Jump to') == -1:
            if text.find('Centers') == -1:
                if text.find('Forwards') == -1:
                    if text.find('Guards') == -1:
                        if text.find('RotoGuru') == -1:
                            list_of_cells.append(text)

    list_of_rows.append(list_of_cells)


with open('bestPlayers.csv', 'w', encoding='UTF8', newline='') as f:
    writer = csv.writer(f)

    # write multiple rows
    writer.writerows(list_of_rows)





