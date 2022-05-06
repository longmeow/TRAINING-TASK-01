import subprocess
import csv

CMD = "tshark -T fields -e ip.version -e ip.src -e ip.dst -e ip.len -e ip.hdr_len -e ip.id -e ip.proto -e ip.ttl -e ip.flags -e ip.frag_offset -e ip.checksum -e ipv6.src -e ipv6.dst -e ipv6.tclass -e ipv6.flow -e ipv6.plen -e ipv6.nxt -e ipv6.hlim -e tcp.srcport -e tcp.dstport -e tcp.seq -e tcp.ack -e tcp.hdr_len -e tcp.window_size -e tcp.checksum -e tcp.urgent_pointer -e udp.srcport -e udp.dstport -e udp.length -e udp.checksum -E separator=, -E header=y"
COUNT = 0
output = subprocess.Popen(CMD, shell = True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)

while True:
    line = output.stdout.readline()
    with open('my_csv.csv', 'a', newline='') as f:
        my_writer = csv.writer(f)
        my_writer.writerow(line.split(","))
    print(line)
    COUNT += 1
    print(COUNT)

    


