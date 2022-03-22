import urllib
for i in range(0, 20000):
    data = urllib.request.urlopen("https://cses.fi/user/{}".format(i)).read().decode('UTF-8')
    print(data[data.find('User'):data.find('User')+15])