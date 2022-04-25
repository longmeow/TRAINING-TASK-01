import pandas as pd
import urllib.request
from datetime import datetime
import time


url = "http://192.168.4.7/"


def get_data(url): 
	with urllib.request.urlopen(url) as f:  
		now = datetime.now()
		current_data = f.read().decode('utf-8').split(" ") 
		temp=(float(current_data[0]))
		light=(float(current_data[1]))
		current_time=(now.strftime("%m/%d/%Y, %H:%M:%S"))
	return current_time, temp, light
  

def make_data_frame(time, temp, light):
	data = {'Time': time, 'Temp': temp, 'Light': light}
	data = pd.DataFrame(data)
	return data


def main(): 
	temp = []
	light = []
	current_time = []
	while True:
		current_time_temp, temp_temp, light_temp = get_data(url)
		current_time.append(current_time_temp)
		temp.append(float(temp_temp))
		light.append(float(light_temp))
		data = make_data_frame(current_time, temp, light)
		print(current_time_temp, temp_temp, light_temp)
		data.to_csv (r'export_dataframe_2.csv', index = True, header=True) 


if __name__ == "__main__":
	main() 
 
  
  