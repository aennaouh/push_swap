import os
import random

def fail(cmd, i, n):
	print (cmd)
	print('TEST ' + ('   '  + str(i))[-3:] + ' ------------------> KO')
	print ('n = ' + str(n))
	exit(0)
for test in range(1000):
	for i in [3, 5, 100, 500]:
		l = list(range(0, i))
		random.shuffle(l)

		l = (str(l).replace(',', '')[1:-1])

		cmd = './push_swap ' + str(l) + ' | wc -l > output'

		os.system (cmd)

		n = eval(open('output').read().strip())

		if (i == 3 and n > 5):
			fail (cmd, i, n)
		if (i == 5 and n > 12):
			fail (cmd, i, n)
		if (i == 100 and n > 700):
			fail (cmd, i, n)
		if (i == 500 and n > 7000):
			fail (cmd, i, n)

		cmd = './push_swap ' + str(l) + ' | ./checker_Mac ' + str(l) + ' > output2'

		os.system (cmd)

		n = open('output2').read().strip()
		print('TEST ' + ('   '  + str(i))[-3:] + ' ------> OK' + 'n')





