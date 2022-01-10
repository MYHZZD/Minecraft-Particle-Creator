#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <windows.h>
#include <gdiplus.h>
#include <CommDlg.h>
#include <ctime>
#pragma comment(lib, "gdiplus.lib")
using namespace std;
using namespace Gdiplus;

float cx[262144];
float cy[262144];
float cz[262144];
float flexible_argument[262144];

int basic_rotate(int i);//������ת
int comproportionation(int i);//������Ч��д��תд������BUG
string writefunction_m1(int i, int x, int y, int z, int tickchange, int tickall, string fname);//������������
string writefunction_m2(int i, int x, int y, int z, int tickchange, int tickall, string fname);//ƿ���������ɣ����ɣ�
string writefunction_m3(int i, int x, int y, int z, int tickchange, int tickall, string fname);//ƿ���������ɣ�������
string writefunction_m4(int i, int x, int y, int z, int tickchange, int tickall, string fname);//ƿ���������ɣ���ɢ��
string writefunction_m5(int i, int x, int y, int z, int tickchange, int tickall, string fname);//�����������ɣ���ɢ��
string writefunction_m6(int i, int x, int y, int z, int tickchange, int tickall, string fname);//�����������ɣ�˲ʱ��
string writefunction_m7(int i, int x, int y, int z, int tickchange, int tickall, string fname);//ƿ���������ɣ�˲ʱ��
string writefunction_m8(int i, int x, int y, int z, int density, int tickall, string fname);//������������ ��̬�ܶ�
int writefunction_m21(int i);//������任���� ģʽ1
int writefunction_m22(int i);//������任���� ģʽ2
int writefunction_m23(int i);//������任���� ģʽ3
int writefunction_m24(int i);//������任���� ģʽ4
float normal_vector_rot(float dx, float dy, float dz, float x, float y, float z, string n);//������ת������һ����׼����

int main()
{
	cout << "��ӭʹ�ñ�����������" << endl
		<< "--------------------------" << endl
		<< "ģʽѡ��" << endl
		<< "0.˵����" << endl
		<< "1.ֱ��" << endl
		<< "2.���κ�����" << endl
		<< "3.���ױ�����" << endl
		<< "4.�߽ױ�����" << endl
		<< "5.���ɶ��κ�����ƿ�ӣ�" << endl
		<< "6.�������κ�����ƿ�ӣ�" << endl
		<< "7.����ֱ�ߣ�ƿ�ӣ�" << endl
		<< "8.����ֱ�ߣ�ƿ�ӣ�" << endl
		<< "9.���ɶ��ױ�������ƿ�ӣ�" << endl
		<< "10.��״���ױ�������ƿ�ӣ�" << endl
		<< "11.����" << endl
		<< "12.��ɢ����" << endl
		<< "13.���ߣ�ƿ�ӣ�" << endl
		<< "14.��ɢ���ߣ�ƿ�ӣ�" << endl
		<< "15.�Զ�������" << endl
		<< "16.��ɢԲ" << endl
		<< "17.������ת����(�û�)" << endl
		<< "18.��������(�û�)" << endl
		<< "19.ƽ��Soma3" << endl
		<< "501.������߿�" << endl
		<< "1000.���ӻ�" << endl
		<< "1001.falling_block" << endl
		<< "1002.�ֳ�ѩ��Ŀ��׼�(�û�)" << endl
		<< "--------------------------" << endl
		<< "ѡ�����ģʽ:";
	int moudle;
	cin >> moudle;

	switch (moudle)
	{
	case 0:
	{
		string docname("information.txt");
		ofstream inforcout(docname);
		inforcout
			<< "ģʽ1 ����˵��:" << endl
			<< "������ꡢ�յ�����:�������֣�����ΪX Y Z��֧�ָ�����ʽ" << endl
			<< "�����ܶ�:ÿtickִ�ж���ָ����ɶ�������" << endl
			<< "ʱ���ܳ�:�ڶ���tick��ִ��ȫ��ָ��" << endl
			<< "��������:��������.mcfunction" << endl
			<< endl
			<< "ģʽ2 ����˵��:" << endl
			<< "���߸߶�:������ߵ������߶Ȳ�" << endl
			<< endl
			<< "ģʽ3 ����˵��:" << endl
			<< "��������:���ױ������Ŀ��Ƶ�" << endl
			<< endl
			<< "ģʽ501 ����˵��:" << endl
			<< "��С:��λΪ����" << endl
			<< "�ܶ�:��λ�������ж��ٸ�" << endl
			<< "�Ƕ�:������ֵ�ֱ�����Y��ת������Z��ת������X��ת���Ұ�˳������ת��������:�ø���ƽ���������������Խ�����ֱ�Ĳ���Ϊ 45 54.7356 0" << endl
			<< "����:д��תд������bug����һ��������xzƽ����ת���ڶ��������ǹ��г̶ȣ�ȡֵ0-90��" << endl
			<< "�Ƿ���ѭ������������ʱ��:����Y��ʹ��ѭ�����������Ƴ���������������ֹ������N������Զ������ʱ��" << endl
			<< "ƽ�Ʒ���:ƽ�Ʒ���������˳��Ϊxyz" << endl
			<< "�ٶȲ���:ƽ���ٶȣ��������ƶ���������ȣ����㹫ʽδ֪�������ؾ������" << endl
			<< "��ɢ�ٶ�:���Ӵ����ķ����ʼ�ٶȲ������������ƶ���������ȣ����㹫ʽδ֪�������ؾ������" << endl
			<< endl
			<< "ģʽ1000 ����˵��:" << endl
			<< "��ɫģʽ:�Ҷȴ���ڰ�ͼƬ����ͼƬ�к�ɫ����ת��Ϊ����" << endl << endl;
		inforcout.close();
		cout << "˵���齫�����ڱ�����ͬĿ¼��" << endl;
	}
	break;
	case 1:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		float a, b, c;//ֱ��ͶӰ
		a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		int i = 0;

		for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
		{
			cx[i] = k * a;
			cy[i] = k * b;
			cz[i] = k * c;
			i++;
		}

		writefunction_m1(i, x, y, z, tickchange, tickall, fname);
	};
	break;
	case 2:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "�������߸߶�" << endl;//�����߶Ȳ�
		int high;
		cin >> high;
		if (high <= y2 - y1)
		{
			for (int checkhigh = 1; checkhigh > 0; checkhigh++)
			{
				cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
				cout << "�������߸߶�" << endl;
				cin >> high;
				if (high > y2 - y1)
					checkhigh = -10;
			}
		}
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		if (y1 == y2)
		{
			double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
			double a2 = high / pow(x0, 2);//���κ���������ϵ��

			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			float a, b, c;
			a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

			int i = 0;

			for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				if (k <= x0)
				{
					cy[i] = k * b + high - a2 * pow(x0 - k, 2);
				}
				else
				{
					cy[i] = k * b + high - a2 * pow(k - x0, 2);
				}
				cz[i] = k * c;
				i++;
			}

			int doc = 0;//ÿ���ļ��м���
			int docchange = 0;//�ļ�����

			for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
			{
				string docc = to_string(docchange);
				string docname = fname + "_" + docc + ".mcfunction";
				ofstream functioncout(docname);
				for (int doc = 0; doc < tickchange; doc++)//ѭ�����
				{
					functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
						<< "particle minecraft:end_rod"
						<< fixed << setprecision(8)
						<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
						<< " 0 0 0"
						<< " 0"
						<< " 0 force @a" << endl;
					jsonoutloop++;
				}
				functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
				functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
				docchange++;
				docc = to_string(docchange);
				string funname = fname + "_" + docc;
				functioncout << "schedule function minecraft:" << funname << " 1t";
				functioncout.close();
				if (docchange == tickall)//���һ���ļ����
				{
					string docc = to_string(docchange);
					string docname = fname + "_" + docc + ".mcfunction";
					ofstream functioncout(docname);
					functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
						<< "particle minecraft:end_rod"
						<< fixed << setprecision(8)
						<< " ~" << x << " ~" << y << " ~" << z
						<< " 0 0 0"
						<< " 0"
						<< " 0 force @a" << endl;
					functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
					functioncout.close();
				}
				else
					jsonoutloop--;
			}

			string docname = fname + ".mcfunction";//������
			ofstream functioncout(docname);
			functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
			functioncout << "function minecraft:" << fname << "_0";
			functioncout.close();
		}
		else if (high > (y2 - y1))
		{
			float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
			float h1 = high - y2 + y1;
			float h2 = y2 - y1;
			if (y2 < y1)
			{
				h1 = high;
				h2 = -1 * h2;
			}

			float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
			float a2 = fabs(h1) / pow(x0, 2);

			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			float a, c;
			a = x / (sqrt(pow(x, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(z, 2)));

			int i = 0;

			for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				cz[i] = k * c;
				if (y2 > y1)
				{
					if (k < (l - x0))
						cy[i] = high - a2 * pow(l - x0 - k, 2);
					else
						cy[i] = high - a2 * pow(k - l + x0, 2);
				}
				else
				{
					if (k < x0)
						cy[i] = high - a2 * pow(x0 - k, 2);
					else
						cy[i] = high - a2 * pow(k - x0, 2);
				}
				i++;
			}

			writefunction_m1(i, x, y, z, tickchange, tickall, fname);
		}
	}
	break;
	case 3:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
		float x3, y3, z3;
		cin >> x3 >> y3 >> z3;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		int i = 0;

		for (double k = 0; k <= 1000; k += (1000 / (tickall * tickchange)))
		{
			double k2 = k / 1000;
			cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
			cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
			cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
			i++;
		}

		writefunction_m1(i, x, y, z, tickchange, tickall, fname);
	}
	break;
	case 4:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;
		cout << "�������߽���" << endl;//n����n-1�����Ƶ�
		int bn;
		cin >> bn;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		int i = 0;

		for (double k = 0; k <= 1000; k += (1000 / (tickall * tickchange)))
		{
			double k2 = k / 1000;
			cx[i] = pow(1 - k2, bn) * 0 + pow(k2, bn) * x;
			cy[i] = pow(1 - k2, bn) * 0 + pow(k2, bn) * y;
			cz[i] = pow(1 - k2, bn) * 0 + pow(k2, bn) * z;
			i++;
		}

		float xkz, ykz, zkz;
		for (int jsxh = 1; jsxh < bn; jsxh++)
		{
			cout << "�������" << jsxh << "�����Ƶ�����:";
			cin >> xkz >> ykz >> zkz;
			xkz -= x1;
			ykz -= y1;
			zkz -= z1;

			i = 0;
			for (double k = 0; k <= 1000; k += (1000 / (tickall * tickchange)))
			{
				double k2 = k / 1000;
				cx[i] += (tgamma(bn + 1)) / (tgamma(bn + 1) * tgamma(jsxh + 1)) * pow(k2, jsxh) * pow(1 - k2, bn - jsxh) * xkz;
				cy[i] += (tgamma(bn + 1)) / (tgamma(bn + 1) * tgamma(jsxh + 1)) * pow(k2, jsxh) * pow(1 - k2, bn - jsxh) * ykz;
				cz[i] += (tgamma(bn + 1)) / (tgamma(bn + 1) * tgamma(jsxh + 1)) * pow(k2, jsxh) * pow(1 - k2, bn - jsxh) * zkz;
				i++;
			}
		}

		writefunction_m1(i, x, y, z, tickchange, tickall, fname);
	}
	break;
	case 5:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "�������߸߶�" << endl;//�����߶Ȳ�
		int high;
		cin >> high;
		if (high <= y2 - y1)
		{
			for (int checkhigh = 1; checkhigh > 0; checkhigh++)
			{
				cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
				cout << "�������߸߶�" << endl;
				cin >> high;
				if (high > y2 - y1)
					checkhigh = -10;
			}
		}
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		if (y1 == y2)
		{
			double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
			double a2 = high / pow(x0, 2);//���κ���������ϵ��

			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			float a, b, c;
			a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

			int i = 0;

			for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				if (k <= x0)
				{
					cy[i] = k * b + high - a2 * pow(x0 - k, 2);
				}
				else
				{
					cy[i] = k * b + high - a2 * pow(k - x0, 2);
				}
				cz[i] = k * c;
				i++;
			}

			writefunction_m2(i, x, y, z, tickchange, tickall, fname);
		}
		else if (high > (y2 - y1))
		{
			float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
			float h1 = high - y2 + y1;
			float h2 = y2 - y1;
			if (y2 < y1)
			{
				h1 = high;
				h2 = -1 * h2;
			}

			float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
			float a2 = fabs(h1) / pow(x0, 2);

			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			float a, c;
			a = x / (sqrt(pow(x, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(z, 2)));

			int i = 0;

			for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				cz[i] = k * c;
				if (y2 > y1)
				{
					if (k < (l - x0))
						cy[i] = high - a2 * pow(l - x0 - k, 2);
					else
						cy[i] = high - a2 * pow(k - l + x0, 2);
				}
				else
				{
					if (k < x0)
						cy[i] = high - a2 * pow(x0 - k, 2);
					else
						cy[i] = high - a2 * pow(k - x0, 2);
				}
				i++;
			}

			writefunction_m2(i, x, y, z, tickchange, tickall, fname);
		}
	}
	break;
	case 6:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "�������߸߶�" << endl;//�����߶Ȳ�
		int high;
		cin >> high;
		if (high <= y2 - y1)
		{
			for (int checkhigh = 1; checkhigh > 0; checkhigh++)
			{
				cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
				cout << "�������߸߶�" << endl;
				cin >> high;
				if (high > y2 - y1)
					checkhigh = -10;
			}
		}
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		if (y1 == y2)
		{
			double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
			double a2 = high / pow(x0, 2);//���κ���������ϵ��

			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			float a, b, c;
			a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

			int i = 0;

			for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				if (k <= x0)
				{
					cy[i] = k * b + high - a2 * pow(x0 - k, 2);
				}
				else
				{
					cy[i] = k * b + high - a2 * pow(k - x0, 2);
				}
				cz[i] = k * c;
				i++;
			}

			writefunction_m3(i, x, y, z, tickchange, tickall, fname);
		}
		else if (high > (y2 - y1))
		{
			float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
			float h1 = high - y2 + y1;
			float h2 = y2 - y1;
			if (y2 < y1)
			{
				h1 = high;
				h2 = -1 * h2;
			}

			float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
			float a2 = fabs(h1) / pow(x0, 2);

			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			float a, c;
			a = x / (sqrt(pow(x, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(z, 2)));

			int i = 0;

			for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				cz[i] = k * c;
				if (y2 > y1)
				{
					if (k < (l - x0))
						cy[i] = high - a2 * pow(l - x0 - k, 2);
					else
						cy[i] = high - a2 * pow(k - l + x0, 2);
				}
				else
				{
					if (k < x0)
						cy[i] = high - a2 * pow(x0 - k, 2);
					else
						cy[i] = high - a2 * pow(k - x0, 2);
				}
				i++;
			}

			writefunction_m3(i, x, y, z, tickchange, tickall, fname);
		}
	}
	break;
	case 7:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		double a, b, c;//ֱ��ͶӰ
		a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		int i = 0;

		for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
		{
			cx[i] = k * a;
			cy[i] = k * b;
			cz[i] = k * c;
			i++;
		}

		writefunction_m2(i, x, y, z, tickchange, tickall, fname);
	};
	break;
	case 8:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		double a, b, c;//ֱ��ͶӰ
		a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		int i = 0;

		for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
		{
			cx[i] = k * a;
			cy[i] = k * b;
			cz[i] = k * c;
			i++;
		}

		writefunction_m3(i, x, y, z, tickchange, tickall, fname);
	};
	break;
	case 9:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
		float x3, y3, z3;
		cin >> x3 >> y3 >> z3;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		int i = 0;

		for (double k = 0; k <= 1000; k += (1000 / (tickall * tickchange)))
		{
			double k2 = k / 1000;
			cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
			cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
			cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
			i++;
		}

		writefunction_m2(i, x, y, z, tickchange, tickall, fname);
	}
	break;
	case 10:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
		float x3, y3, z3;
		cin >> x3 >> y3 >> z3;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		int i = 0;

		for (double k = 0; k <= 1000; k += (1000 / (tickall * tickchange)))
		{
			double k2 = k / 1000;
			cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
			cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
			cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
			i++;
		}

		writefunction_m3(i, x, y, z, tickchange, tickall, fname);
	}
	break;
	case 11:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		float tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		float tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;
		cout << "��ѡ����ģ��,0ֱ��,1���κ���,2���ױ�����" << endl;
		int funmodle;
		cin >> funmodle;
		int high;
		float x3, y3, z3;
		if (funmodle == 1)
		{
			cout << "�������߸߶�" << endl;//�����߶Ȳ�		
			cin >> high;
			if (high <= y2 - y1)
			{
				for (int checkhigh = 1; checkhigh > 0; checkhigh++)
				{
					cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
					cout << "�������߸߶�" << endl;
					cin >> high;
					if (high > y2 - y1)
						checkhigh = -10;
				}
			}
		}
		else if (funmodle == 2)
		{
			cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
			cin >> x3 >> y3 >> z3;
		}

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;
		int i = 0;

		switch (funmodle)//���ɻ�������ģ��
		{
		case 0:
		{
			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			double a, b, c;//ֱ��ͶӰ
			a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

			for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				cy[i] = k * b;
				cz[i] = k * c;
				i++;
			}
		}
		break;
		case 1:
		{
			if (y1 == y2)
			{
				double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
				double a2 = high / pow(x0, 2);//���κ���������ϵ��

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;

				float a, b, c;
				a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
				b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
				c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

				for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
				{
					cx[i] = k * a;
					if (k <= x0)
					{
						cy[i] = k * b + high - a2 * pow(x0 - k, 2);
					}
					else
					{
						cy[i] = k * b + high - a2 * pow(k - x0, 2);
					}
					cz[i] = k * c;
					i++;
				}
			}
			else if (high > (y2 - y1))
			{
				float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
				float h1 = high - y2 + y1;
				float h2 = y2 - y1;
				if (y2 < y1)
				{
					h1 = high;
					h2 = -1 * h2;
				}

				float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
				float a2 = fabs(h1) / pow(x0, 2);

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;

				float a, c;
				a = x / (sqrt(pow(x, 2) + pow(z, 2)));
				c = z / (sqrt(pow(x, 2) + pow(z, 2)));

				for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
				{
					cx[i] = k * a;
					cz[i] = k * c;
					if (y2 > y1)
					{
						if (k < (l - x0))
							cy[i] = high - a2 * pow(l - x0 - k, 2);
						else
							cy[i] = high - a2 * pow(k - l + x0, 2);
					}
					else
					{
						if (k < x0)
							cy[i] = high - a2 * pow(x0 - k, 2);
						else
							cy[i] = high - a2 * pow(k - x0, 2);
					}
					i++;
				}
			}
		}
		break;
		case 2:
		{
			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			for (double k = 0; k <= 100000; k += (100000 / (tickall * tickchange)))
			{
				double k2 = k / 100000;
				cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
				cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
				cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
				i++;
			}
		}
		break;
		}

		cout << "�ǶȲ���" << endl;
		float anglell;
		cin >> anglell;
		anglell = (anglell / 180) * 3.1415926535898;
		cout << "������" << endl;
		float ll;
		cin >> ll;

		float xadd, yadd, zadd;
		float dxp, dyp, dzp;
		float ii = i;
		for (int j = 0; j < i - 1; j++)
		{
			float dxn = cx[j + 1] - cx[j];
			float dyn = cy[j + 1] - cy[j];
			float dzn = cz[j + 1] - cz[j];

			if (j == 0)
			{
				dxp = cx[j + 1] - cx[j];
				dyp = cy[j + 1] - cy[j];
				dzp = cz[j + 1] - cz[j];
			}

			float dx = (dxn + dxp) / 2;
			float dy = (dyn + dyp) / 2;
			float dz = (dzn + dzp) / 2;

			dxp = dxn;
			dyp = dyn;
			dzp = dzn;

			yadd = 0;
			if (i % 2 == 0)
			{
				if (j < (i / 2))
				{
					xadd = (2 * j / ii) * ll * cos(anglell * j);
					zadd = (2 * j / ii) * ll * sin(anglell * j);
				}
				else if (j == (i / 2))
				{
					xadd = ll * cos(anglell * j);
					zadd = ll * sin(anglell * j);
				}
				else
				{
					xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j);
					zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j);
				}
			}
			else
			{
				if (j < ((i + 1) / 2))
				{
					xadd = (2 * j / (ii - 1)) * ll * cos(anglell * j);
					zadd = (2 * j / (ii - 1)) * ll * sin(anglell * j);
				}
				else
				{
					xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j);
					zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j);
				}
			}

			string n;
			n = "x";
			float xaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);
			n = "y";
			float yaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);
			n = "z";
			float zaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);

			cx[j] += xaddp;
			cy[j] += yaddp;
			cz[j] += zaddp;
		}
		writefunction_m1(i, x, y, z, tickchange, tickall, fname);
	}
	break;
	case 12:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		float tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		float tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;
		cout << "��ѡ����ģ��,0ֱ��,1���κ���,2���ױ�����" << endl;
		int funmodle;
		cin >> funmodle;
		int high;
		float x3, y3, z3;
		if (funmodle == 1)
		{
			cout << "�������߸߶�" << endl;//�����߶Ȳ�		
			cin >> high;
			if (high <= y2 - y1)
			{
				for (int checkhigh = 1; checkhigh > 0; checkhigh++)
				{
					cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
					cout << "�������߸߶�" << endl;
					cin >> high;
					if (high > y2 - y1)
						checkhigh = -10;
				}
			}
		}
		else if (funmodle == 2)
		{
			cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
			cin >> x3 >> y3 >> z3;
		}

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;
		int i = 0;

		switch (funmodle)//���ɻ�������ģ��
		{
		case 0:
		{
			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			double a, b, c;//ֱ��ͶӰ
			a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

			for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				cy[i] = k * b;
				cz[i] = k * c;
				i++;
			}
		}
		break;
		case 1:
		{
			if (y1 == y2)
			{
				double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
				double a2 = high / pow(x0, 2);//���κ���������ϵ��

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;

				float a, b, c;
				a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
				b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
				c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

				for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
				{
					cx[i] = k * a;
					if (k <= x0)
					{
						cy[i] = k * b + high - a2 * pow(x0 - k, 2);
					}
					else
					{
						cy[i] = k * b + high - a2 * pow(k - x0, 2);
					}
					cz[i] = k * c;
					i++;
				}
			}
			else if (high > (y2 - y1))
			{
				float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
				float h1 = high - y2 + y1;
				float h2 = y2 - y1;
				if (y2 < y1)
				{
					h1 = high;
					h2 = -1 * h2;
				}

				float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
				float a2 = fabs(h1) / pow(x0, 2);

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;

				float a, c;
				a = x / (sqrt(pow(x, 2) + pow(z, 2)));
				c = z / (sqrt(pow(x, 2) + pow(z, 2)));

				for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
				{
					cx[i] = k * a;
					cz[i] = k * c;
					if (y2 > y1)
					{
						if (k < (l - x0))
							cy[i] = high - a2 * pow(l - x0 - k, 2);
						else
							cy[i] = high - a2 * pow(k - l + x0, 2);
					}
					else
					{
						if (k < x0)
							cy[i] = high - a2 * pow(x0 - k, 2);
						else
							cy[i] = high - a2 * pow(k - x0, 2);
					}
					i++;
				}
			}
		}
		break;
		case 2:
		{
			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			for (double k = 0; k <= 100000; k += (100000 / (tickall * tickchange)))
			{
				double k2 = k / 100000;
				cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
				cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
				cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
				i++;
			}
		}
		break;
		}

		cout << "�ǶȲ���" << endl;
		float anglell;
		cin >> anglell;
		anglell = (anglell / 180) * 3.1415926535898;
		cout << "���ϵ��" << endl;
		float ll;
		cin >> ll;

		float xadd, yadd, zadd;
		float dxp, dyp, dzp;
		float ii = i;

		for (int j = 0; j < i - 1; j++)
		{
			float dxn = cx[j + 1] - cx[j];
			float dyn = cy[j + 1] - cy[j];
			float dzn = cz[j + 1] - cz[j];

			if (j == 0)
			{
				dxp = cx[j + 1] - cx[j];
				dyp = cy[j + 1] - cy[j];
				dzp = cz[j + 1] - cz[j];
			}

			float dx = (dxn + dxp) / 2;
			float dy = (dyn + dyp) / 2;
			float dz = (dzn + dzp) / 2;

			dxp = dxn;
			dyp = dyn;
			dzp = dzn;

			yadd = 0;
			xadd = ll * cos(anglell * j);
			zadd = ll * sin(anglell * j);

			string n;
			n = "x";
			float xaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);
			n = "y";
			float yaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);
			n = "z";
			float zaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);

			cx[j + i + 1] = xaddp;
			cy[j + i + 1] = yaddp;
			cz[j + i + 1] = zaddp;
		}
		writefunction_m5(i, x, y, z, tickchange, tickall, fname);
	}
	break;
	case 13:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		float tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		float tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;
		cout << "��ѡ����ģ��,0ֱ��,1���κ���,2���ױ�����" << endl;
		int funmodle;
		cin >> funmodle;
		int high;
		float x3, y3, z3;
		if (funmodle == 1)
		{
			cout << "�������߸߶�" << endl;//�����߶Ȳ�		
			cin >> high;
			if (high <= y2 - y1)
			{
				for (int checkhigh = 1; checkhigh > 0; checkhigh++)
				{
					cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
					cout << "�������߸߶�" << endl;
					cin >> high;
					if (high > y2 - y1)
						checkhigh = -10;
				}
			}
		}
		else if (funmodle == 2)
		{
			cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
			cin >> x3 >> y3 >> z3;
		}

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;
		int i = 0;

		switch (funmodle)//���ɻ�������ģ��
		{
		case 0:
		{
			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			double a, b, c;//ֱ��ͶӰ
			a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

			for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				cy[i] = k * b;
				cz[i] = k * c;
				i++;
			}
		}
		break;
		case 1:
		{
			if (y1 == y2)
			{
				double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
				double a2 = high / pow(x0, 2);//���κ���������ϵ��

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;

				float a, b, c;
				a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
				b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
				c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

				for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
				{
					cx[i] = k * a;
					if (k <= x0)
					{
						cy[i] = k * b + high - a2 * pow(x0 - k, 2);
					}
					else
					{
						cy[i] = k * b + high - a2 * pow(k - x0, 2);
					}
					cz[i] = k * c;
					i++;
				}
			}
			else if (high > (y2 - y1))
			{
				float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
				float h1 = high - y2 + y1;
				float h2 = y2 - y1;
				if (y2 < y1)
				{
					h1 = high;
					h2 = -1 * h2;
				}

				float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
				float a2 = fabs(h1) / pow(x0, 2);

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;

				float a, c;
				a = x / (sqrt(pow(x, 2) + pow(z, 2)));
				c = z / (sqrt(pow(x, 2) + pow(z, 2)));

				for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
				{
					cx[i] = k * a;
					cz[i] = k * c;
					if (y2 > y1)
					{
						if (k < (l - x0))
							cy[i] = high - a2 * pow(l - x0 - k, 2);
						else
							cy[i] = high - a2 * pow(k - l + x0, 2);
					}
					else
					{
						if (k < x0)
							cy[i] = high - a2 * pow(x0 - k, 2);
						else
							cy[i] = high - a2 * pow(k - x0, 2);
					}
					i++;
				}
			}
		}
		break;
		case 2:
		{
			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			for (double k = 0; k <= 100000; k += (100000 / (tickall * tickchange)))
			{
				double k2 = k / 100000;
				cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
				cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
				cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
				i++;
			}
		}
		break;
		}

		cout << "�ǶȲ���" << endl;
		float anglell;
		cin >> anglell;
		anglell = (anglell / 180) * 3.1415926535898;
		cout << "������" << endl;
		float ll;
		cin >> ll;

		float xadd, yadd, zadd;
		float dxp, dyp, dzp;
		float ii = i;
		for (int j = 0; j < i - 1; j++)
		{
			float dxn = cx[j + 1] - cx[j];
			float dyn = cy[j + 1] - cy[j];
			float dzn = cz[j + 1] - cz[j];

			if (j == 0)
			{
				dxp = cx[j + 1] - cx[j];
				dyp = cy[j + 1] - cy[j];
				dzp = cz[j + 1] - cz[j];
			}

			float dx = (dxn + dxp) / 2;
			float dy = (dyn + dyp) / 2;
			float dz = (dzn + dzp) / 2;

			dxp = dxn;
			dyp = dyn;
			dzp = dzn;

			yadd = 0;
			if (i % 2 == 0)
			{
				if (j < (i / 2))
				{
					xadd = (2 * j / ii) * ll * cos(anglell * j);
					zadd = (2 * j / ii) * ll * sin(anglell * j);
				}
				else if (j == (i / 2))
				{
					xadd = ll * cos(anglell * j);
					zadd = ll * sin(anglell * j);
				}
				else
				{
					xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j);
					zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j);
				}
			}
			else
			{
				if (j < ((i + 1) / 2))
				{
					xadd = (2 * j / (ii - 1)) * ll * cos(anglell * j);
					zadd = (2 * j / (ii - 1)) * ll * sin(anglell * j);
				}
				else
				{
					xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j);
					zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j);
				}
			}

			string n;
			n = "x";
			float xaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);
			n = "y";
			float yaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);
			n = "z";
			float zaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);

			cx[j] += xaddp;
			cy[j] += yaddp;
			cz[j] += zaddp;
		}
		writefunction_m3(i, x, y, z, tickchange, tickall, fname);
	}
	break;
	case 14:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		float tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		float tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;
		cout << "��ѡ����ģ��,0ֱ��,1���κ���,2���ױ�����" << endl;
		int funmodle;
		cin >> funmodle;
		int high;
		float x3, y3, z3;
		if (funmodle == 1)
		{
			cout << "�������߸߶�" << endl;//�����߶Ȳ�		
			cin >> high;
			if (high <= y2 - y1)
			{
				for (int checkhigh = 1; checkhigh > 0; checkhigh++)
				{
					cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
					cout << "�������߸߶�" << endl;
					cin >> high;
					if (high > y2 - y1)
						checkhigh = -10;
				}
			}
		}
		else if (funmodle == 2)
		{
			cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
			cin >> x3 >> y3 >> z3;
		}

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;
		int i = 0;

		switch (funmodle)//���ɻ�������ģ��
		{
		case 0:
		{
			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			double a, b, c;//ֱ��ͶӰ
			a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
			c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

			for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
			{
				cx[i] = k * a;
				cy[i] = k * b;
				cz[i] = k * c;
				i++;
			}
		}
		break;
		case 1:
		{
			if (y1 == y2)
			{
				double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
				double a2 = high / pow(x0, 2);//���κ���������ϵ��

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;

				float a, b, c;
				a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
				b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
				c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

				for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
				{
					cx[i] = k * a;
					if (k <= x0)
					{
						cy[i] = k * b + high - a2 * pow(x0 - k, 2);
					}
					else
					{
						cy[i] = k * b + high - a2 * pow(k - x0, 2);
					}
					cz[i] = k * c;
					i++;
				}
			}
			else if (high > (y2 - y1))
			{
				float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
				float h1 = high - y2 + y1;
				float h2 = y2 - y1;
				if (y2 < y1)
				{
					h1 = high;
					h2 = -1 * h2;
				}

				float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
				float a2 = fabs(h1) / pow(x0, 2);

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;

				float a, c;
				a = x / (sqrt(pow(x, 2) + pow(z, 2)));
				c = z / (sqrt(pow(x, 2) + pow(z, 2)));

				for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
				{
					cx[i] = k * a;
					cz[i] = k * c;
					if (y2 > y1)
					{
						if (k < (l - x0))
							cy[i] = high - a2 * pow(l - x0 - k, 2);
						else
							cy[i] = high - a2 * pow(k - l + x0, 2);
					}
					else
					{
						if (k < x0)
							cy[i] = high - a2 * pow(x0 - k, 2);
						else
							cy[i] = high - a2 * pow(k - x0, 2);
					}
					i++;
				}
			}
		}
		break;
		case 2:
		{
			float x, y, z;//��ֵ
			x = x2 - x1;
			y = y2 - y1;
			z = z2 - z1;

			for (double k = 0; k <= 100000; k += (100000 / (tickall * tickchange)))
			{
				double k2 = k / 100000;
				cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
				cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
				cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
				i++;
			}
		}
		break;
		}

		cout << "�ǶȲ���" << endl;
		float anglell;
		cin >> anglell;
		anglell = (anglell / 180) * 3.1415926535898;
		cout << "���ϵ��" << endl;
		float ll;
		cin >> ll;

		float xadd, yadd, zadd;
		float dxp, dyp, dzp;
		float ii = i;

		for (int j = 0; j < i - 1; j++)
		{
			float dxn = cx[j + 1] - cx[j];
			float dyn = cy[j + 1] - cy[j];
			float dzn = cz[j + 1] - cz[j];

			if (j == 0)
			{
				dxp = cx[j + 1] - cx[j];
				dyp = cy[j + 1] - cy[j];
				dzp = cz[j + 1] - cz[j];
			}

			float dx = (dxn + dxp) / 2;
			float dy = (dyn + dyp) / 2;
			float dz = (dzn + dzp) / 2;

			dxp = dxn;
			dyp = dyn;
			dzp = dzn;

			yadd = 0;
			xadd = ll * cos(anglell * j);
			zadd = ll * sin(anglell * j);

			string n;
			n = "x";
			float xaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);
			n = "y";
			float yaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);
			n = "z";
			float zaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, n);

			cx[j + i + 1] = xaddp;
			cy[j + i + 1] = yaddp;
			cz[j + i + 1] = zaddp;
		}

		writefunction_m4(i, x, y, z, tickchange, tickall, fname);
	}
	break;
	case 15:
	{
		cout << "���뺯������" << endl;
		string ffname;
		cin >> ffname;

		for (int loop15 = 1; loop15 != 0; loop15++)
		{
			cout << "�����" << loop15 << "�����߲���:";
			cout << "ģʽѡ��" << endl
				<< "1.����" << endl
				<< "2.��ɢ����" << endl
				<< "3.���ߣ�ƿ�ӣ�" << endl
				<< "4.��ɢ���ߣ�ƿ�ӣ�" << endl
				<< "ѡ�����ģʽ:";
			int module15;
			cin >> module15;
			string fname = ffname;

			switch (module15)
			{
			case 1:
			{
				cout << "�����������" << endl;
				float x1, y1, z1;
				cin >> x1 >> y1 >> z1;
				cout << "�����յ�����" << endl;
				float x2, y2, z2;
				cin >> x2 >> y2 >> z2;
				cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
				float tickchange;
				cin >> tickchange;
				cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
				float tickall;
				cin >> tickall;
				cout << "��ѡ����ģ��,0ֱ��,1���κ���,2���ױ�����" << endl;
				int funmodle;
				cin >> funmodle;
				int high;
				float x3, y3, z3;
				if (funmodle == 1)
				{
					cout << "�������߸߶�" << endl;//�����߶Ȳ�		
					cin >> high;
					if (high <= y2 - y1)
					{
						for (int checkhigh = 1; checkhigh > 0; checkhigh++)
						{
							cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
							cout << "�������߸߶�" << endl;
							cin >> high;
							if (high > y2 - y1)
								checkhigh = -10;
						}
					}
				}
				else if (funmodle == 2)
				{
					cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
					cin >> x3 >> y3 >> z3;
				}

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;
				int i = 0;

				switch (funmodle)//���ɻ�������ģ��
				{
				case 0:
				{
					float x, y, z;//��ֵ
					x = x2 - x1;
					y = y2 - y1;
					z = z2 - z1;

					double a, b, c;//ֱ��ͶӰ
					a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
					b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
					c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

					for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
					{
						cx[i] = k * a;
						cy[i] = k * b;
						cz[i] = k * c;
						i++;
					}
				}
				break;
				case 1:
				{
					if (y1 == y2)
					{
						double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
						double a2 = high / pow(x0, 2);//���κ���������ϵ��

						float x, y, z;//��ֵ
						x = x2 - x1;
						y = y2 - y1;
						z = z2 - z1;

						float a, b, c;
						a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
						b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
						c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

						for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
						{
							cx[i] = k * a;
							if (k <= x0)
							{
								cy[i] = k * b + high - a2 * pow(x0 - k, 2);
							}
							else
							{
								cy[i] = k * b + high - a2 * pow(k - x0, 2);
							}
							cz[i] = k * c;
							i++;
						}
					}
					else if (high > (y2 - y1))
					{
						float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
						float h1 = high - y2 + y1;
						float h2 = y2 - y1;
						if (y2 < y1)
						{
							h1 = high;
							h2 = -1 * h2;
						}

						float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
						float a2 = fabs(h1) / pow(x0, 2);

						float x, y, z;//��ֵ
						x = x2 - x1;
						y = y2 - y1;
						z = z2 - z1;

						float a, c;
						a = x / (sqrt(pow(x, 2) + pow(z, 2)));
						c = z / (sqrt(pow(x, 2) + pow(z, 2)));

						for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
						{
							cx[i] = k * a;
							cz[i] = k * c;
							if (y2 > y1)
							{
								if (k < (l - x0))
									cy[i] = high - a2 * pow(l - x0 - k, 2);
								else
									cy[i] = high - a2 * pow(k - l + x0, 2);
							}
							else
							{
								if (k < x0)
									cy[i] = high - a2 * pow(x0 - k, 2);
								else
									cy[i] = high - a2 * pow(k - x0, 2);
							}
							i++;
						}
					}
				}
				break;
				case 2:
				{
					float x, y, z;//��ֵ
					x = x2 - x1;
					y = y2 - y1;
					z = z2 - z1;

					for (double k = 0; k <= 100000; k += (100000 / (tickall * tickchange)))
					{
						double k2 = k / 100000;
						cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
						cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
						cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
						i++;
					}
				}
				break;
				}

				cout << "�ǶȲ���" << endl;
				float anglell;
				cin >> anglell;
				cout << "����λ" << endl;
				float anglell0;
				cin >> anglell0;
				anglell = (anglell / 180) * 3.1415926535898;
				anglell0 = (anglell0 / 180) * 3.1415926535898;
				cout << "������" << endl;
				float ll;
				cin >> ll;

				float xadd, yadd, zadd;
				float dxp, dyp, dzp;
				float ii = i;
				for (int j = 0; j < i - 1; j++)
				{
					float dxn = cx[j + 1] - cx[j];
					float dyn = cy[j + 1] - cy[j];
					float dzn = cz[j + 1] - cz[j];

					if (j == 0)
					{
						dxp = cx[j + 1] - cx[j];
						dyp = cy[j + 1] - cy[j];
						dzp = cz[j + 1] - cz[j];
					}

					float dx = (dxn + dxp) / 2;
					float dy = (dyn + dyp) / 2;
					float dz = (dzn + dzp) / 2;

					dxp = dxn;
					dyp = dyn;
					dzp = dzn;

					yadd = 0;
					if (i % 2 == 0)
					{
						if (j < (i / 2))
						{
							xadd = (2 * j / ii) * ll * cos(anglell * j + anglell0);
							zadd = (2 * j / ii) * ll * sin(anglell * j + anglell0);
						}
						else if (j == (i / 2))
						{
							xadd = ll * cos(anglell * j + anglell0);
							zadd = ll * sin(anglell * j + anglell0);
						}
						else
						{
							xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j + anglell0);
							zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j + anglell0);
						}
					}
					else
					{
						if (j < ((i + 1) / 2))
						{
							xadd = (2 * j / (ii - 1)) * ll * cos(anglell * j + anglell0);
							zadd = (2 * j / (ii - 1)) * ll * sin(anglell * j + anglell0);
						}
						else
						{
							xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j + anglell0);
							zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j + anglell0);
						}
					}

					float xaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "x");
					float yaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "y");
					float zaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "z");

					cx[j] += xaddp;
					cy[j] += yaddp;
					cz[j] += zaddp;
				}

				string smodule15 = to_string(loop15);
				fname = fname + "p" + smodule15;

				writefunction_m1(i, x, y, z, tickchange, tickall, fname);
			}
			break;
			case 2:
			{
				cout << "�����������" << endl;
				float x1, y1, z1;
				cin >> x1 >> y1 >> z1;
				cout << "�����յ�����" << endl;
				float x2, y2, z2;
				cin >> x2 >> y2 >> z2;
				cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
				float tickchange;
				cin >> tickchange;
				cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
				float tickall;
				cin >> tickall;
				cout << "��ѡ����ģ��,0ֱ��,1���κ���,2���ױ�����" << endl;
				int funmodle;
				cin >> funmodle;
				int high;
				float x3, y3, z3;
				if (funmodle == 1)
				{
					cout << "�������߸߶�" << endl;//�����߶Ȳ�		
					cin >> high;
					if (high <= y2 - y1)
					{
						for (int checkhigh = 1; checkhigh > 0; checkhigh++)
						{
							cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
							cout << "�������߸߶�" << endl;
							cin >> high;
							if (high > y2 - y1)
								checkhigh = -10;
						}
					}
				}
				else if (funmodle == 2)
				{
					cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
					cin >> x3 >> y3 >> z3;
				}

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;
				int i = 0;

				switch (funmodle)//���ɻ�������ģ��
				{
				case 0:
				{
					float x, y, z;//��ֵ
					x = x2 - x1;
					y = y2 - y1;
					z = z2 - z1;

					double a, b, c;//ֱ��ͶӰ
					a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
					b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
					c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

					for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
					{
						cx[i] = k * a;
						cy[i] = k * b;
						cz[i] = k * c;
						i++;
					}
				}
				break;
				case 1:
				{
					if (y1 == y2)
					{
						double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
						double a2 = high / pow(x0, 2);//���κ���������ϵ��

						float x, y, z;//��ֵ
						x = x2 - x1;
						y = y2 - y1;
						z = z2 - z1;

						float a, b, c;
						a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
						b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
						c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

						for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
						{
							cx[i] = k * a;
							if (k <= x0)
							{
								cy[i] = k * b + high - a2 * pow(x0 - k, 2);
							}
							else
							{
								cy[i] = k * b + high - a2 * pow(k - x0, 2);
							}
							cz[i] = k * c;
							i++;
						}
					}
					else if (high > (y2 - y1))
					{
						float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
						float h1 = high - y2 + y1;
						float h2 = y2 - y1;
						if (y2 < y1)
						{
							h1 = high;
							h2 = -1 * h2;
						}

						float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
						float a2 = fabs(h1) / pow(x0, 2);

						float x, y, z;//��ֵ
						x = x2 - x1;
						y = y2 - y1;
						z = z2 - z1;

						float a, c;
						a = x / (sqrt(pow(x, 2) + pow(z, 2)));
						c = z / (sqrt(pow(x, 2) + pow(z, 2)));

						for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
						{
							cx[i] = k * a;
							cz[i] = k * c;
							if (y2 > y1)
							{
								if (k < (l - x0))
									cy[i] = high - a2 * pow(l - x0 - k, 2);
								else
									cy[i] = high - a2 * pow(k - l + x0, 2);
							}
							else
							{
								if (k < x0)
									cy[i] = high - a2 * pow(x0 - k, 2);
								else
									cy[i] = high - a2 * pow(k - x0, 2);
							}
							i++;
						}
					}
				}
				break;
				case 2:
				{
					float x, y, z;//��ֵ
					x = x2 - x1;
					y = y2 - y1;
					z = z2 - z1;

					for (double k = 0; k <= 100000; k += (100000 / (tickall * tickchange)))
					{
						double k2 = k / 100000;
						cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
						cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
						cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
						i++;
					}
				}
				break;
				}

				cout << "�ǶȲ���" << endl;
				float anglell;
				cin >> anglell;
				cout << "����λ" << endl;
				float anglell0;
				cin >> anglell0;
				anglell = (anglell / 180) * 3.1415926535898;
				anglell0 = (anglell0 / 180) * 3.1415926535898;
				cout << "������" << endl;
				float ll;
				cin >> ll;

				float xadd, yadd, zadd;
				float dxp, dyp, dzp;
				float ii = i;
				for (int j = 0; j < i - 1; j++)
				{
					float dxn = cx[j + 1] - cx[j];
					float dyn = cy[j + 1] - cy[j];
					float dzn = cz[j + 1] - cz[j];

					if (j == 0)
					{
						dxp = cx[j + 1] - cx[j];
						dyp = cy[j + 1] - cy[j];
						dzp = cz[j + 1] - cz[j];
					}

					float dx = (dxn + dxp) / 2;
					float dy = (dyn + dyp) / 2;
					float dz = (dzn + dzp) / 2;

					dxp = dxn;
					dyp = dyn;
					dzp = dzn;

					yadd = 0;
					if (i % 2 == 0)
					{
						if (j < (i / 2))
						{
							xadd = (2 * j / ii) * ll * cos(anglell * j + anglell0);
							zadd = (2 * j / ii) * ll * sin(anglell * j + anglell0);
						}
						else if (j == (i / 2))
						{
							xadd = ll * cos(anglell * j + anglell0);
							zadd = ll * sin(anglell * j + anglell0);
						}
						else
						{
							xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j + anglell0);
							zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j + anglell0);
						}
					}
					else
					{
						if (j < ((i + 1) / 2))
						{
							xadd = (2 * j / (ii - 1)) * ll * cos(anglell * j + anglell0);
							zadd = (2 * j / (ii - 1)) * ll * sin(anglell * j + anglell0);
						}
						else
						{
							xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j + anglell0);
							zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j + anglell0);
						}
					}

					float xaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "x");
					float yaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "y");
					float zaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "z");

					cx[j + i + 1] = xaddp;
					cy[j + i + 1] = yaddp;
					cz[j + i + 1] = zaddp;
				}

				string smodule15 = to_string(loop15);
				fname = fname + "p" + smodule15;

				writefunction_m5(i, x, y, z, tickchange, tickall, fname);
			}
			break;
			case 3:
			{
				cout << "�����������" << endl;
				float x1, y1, z1;
				cin >> x1 >> y1 >> z1;
				cout << "�����յ�����" << endl;
				float x2, y2, z2;
				cin >> x2 >> y2 >> z2;
				cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
				float tickchange;
				cin >> tickchange;
				cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
				float tickall;
				cin >> tickall;
				cout << "��ѡ����ģ��,0ֱ��,1���κ���,2���ױ�����" << endl;
				int funmodle;
				cin >> funmodle;
				int high;
				float x3, y3, z3;
				if (funmodle == 1)
				{
					cout << "�������߸߶�" << endl;//�����߶Ȳ�		
					cin >> high;
					if (high <= y2 - y1)
					{
						for (int checkhigh = 1; checkhigh > 0; checkhigh++)
						{
							cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
							cout << "�������߸߶�" << endl;
							cin >> high;
							if (high > y2 - y1)
								checkhigh = -10;
						}
					}
				}
				else if (funmodle == 2)
				{
					cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
					cin >> x3 >> y3 >> z3;
				}

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;
				int i = 0;

				switch (funmodle)//���ɻ�������ģ��
				{
				case 0:
				{
					float x, y, z;//��ֵ
					x = x2 - x1;
					y = y2 - y1;
					z = z2 - z1;

					double a, b, c;//ֱ��ͶӰ
					a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
					b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
					c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

					for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
					{
						cx[i] = k * a;
						cy[i] = k * b;
						cz[i] = k * c;
						i++;
					}
				}
				break;
				case 1:
				{
					if (y1 == y2)
					{
						double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
						double a2 = high / pow(x0, 2);//���κ���������ϵ��

						float x, y, z;//��ֵ
						x = x2 - x1;
						y = y2 - y1;
						z = z2 - z1;

						float a, b, c;
						a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
						b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
						c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

						for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
						{
							cx[i] = k * a;
							if (k <= x0)
							{
								cy[i] = k * b + high - a2 * pow(x0 - k, 2);
							}
							else
							{
								cy[i] = k * b + high - a2 * pow(k - x0, 2);
							}
							cz[i] = k * c;
							i++;
						}
					}
					else if (high > (y2 - y1))
					{
						float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
						float h1 = high - y2 + y1;
						float h2 = y2 - y1;
						if (y2 < y1)
						{
							h1 = high;
							h2 = -1 * h2;
						}

						float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
						float a2 = fabs(h1) / pow(x0, 2);

						float x, y, z;//��ֵ
						x = x2 - x1;
						y = y2 - y1;
						z = z2 - z1;

						float a, c;
						a = x / (sqrt(pow(x, 2) + pow(z, 2)));
						c = z / (sqrt(pow(x, 2) + pow(z, 2)));

						for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
						{
							cx[i] = k * a;
							cz[i] = k * c;
							if (y2 > y1)
							{
								if (k < (l - x0))
									cy[i] = high - a2 * pow(l - x0 - k, 2);
								else
									cy[i] = high - a2 * pow(k - l + x0, 2);
							}
							else
							{
								if (k < x0)
									cy[i] = high - a2 * pow(x0 - k, 2);
								else
									cy[i] = high - a2 * pow(k - x0, 2);
							}
							i++;
						}
					}
				}
				break;
				case 2:
				{
					float x, y, z;//��ֵ
					x = x2 - x1;
					y = y2 - y1;
					z = z2 - z1;

					for (double k = 0; k <= 100000; k += (100000 / (tickall * tickchange)))
					{
						double k2 = k / 100000;
						cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
						cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
						cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
						i++;
					}
				}
				break;
				}

				cout << "�ǶȲ���" << endl;
				float anglell;
				cin >> anglell;
				cout << "����λ" << endl;
				float anglell0;
				cin >> anglell0;
				anglell = (anglell / 180) * 3.1415926535898;
				anglell0 = (anglell0 / 180) * 3.1415926535898;
				cout << "������" << endl;
				float ll;
				cin >> ll;

				float xadd, yadd, zadd;
				float dxp, dyp, dzp;
				float ii = i;
				for (int j = 0; j < i - 1; j++)
				{
					float dxn = cx[j + 1] - cx[j];
					float dyn = cy[j + 1] - cy[j];
					float dzn = cz[j + 1] - cz[j];

					if (j == 0)
					{
						dxp = cx[j + 1] - cx[j];
						dyp = cy[j + 1] - cy[j];
						dzp = cz[j + 1] - cz[j];
					}

					float dx = (dxn + dxp) / 2;
					float dy = (dyn + dyp) / 2;
					float dz = (dzn + dzp) / 2;

					dxp = dxn;
					dyp = dyn;
					dzp = dzn;

					yadd = 0;
					if (i % 2 == 0)
					{
						if (j < (i / 2))
						{
							xadd = (2 * j / ii) * ll * cos(anglell * j + anglell0);
							zadd = (2 * j / ii) * ll * sin(anglell * j + anglell0);
						}
						else if (j == (i / 2))
						{
							xadd = ll * cos(anglell * j + anglell0);
							zadd = ll * sin(anglell * j + anglell0);
						}
						else
						{
							xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j + anglell0);
							zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j + anglell0);
						}
					}
					else
					{
						if (j < ((i + 1) / 2))
						{
							xadd = (2 * j / (ii - 1)) * ll * cos(anglell * j + anglell0);
							zadd = (2 * j / (ii - 1)) * ll * sin(anglell * j + anglell0);
						}
						else
						{
							xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j + anglell0);
							zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j + anglell0);
						}
					}

					float xaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "x");
					float yaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "y");
					float zaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "z");

					cx[j] += xaddp;
					cy[j] += yaddp;
					cz[j] += zaddp;
				}

				string smodule15 = to_string(loop15);
				fname = fname + "p" + smodule15;

				writefunction_m3(i, x, y, z, tickchange, tickall, fname);
			}
			break;
			case 4:
			{
				cout << "�����������" << endl;
				float x1, y1, z1;
				cin >> x1 >> y1 >> z1;
				cout << "�����յ�����" << endl;
				float x2, y2, z2;
				cin >> x2 >> y2 >> z2;
				cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
				float tickchange;
				cin >> tickchange;
				cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
				float tickall;
				cin >> tickall;
				cout << "��ѡ����ģ��,0ֱ��,1���κ���,2���ױ�����" << endl;
				int funmodle;
				cin >> funmodle;
				int high;
				float x3, y3, z3;
				if (funmodle == 1)
				{
					cout << "�������߸߶�" << endl;//�����߶Ȳ�		
					cin >> high;
					if (high <= y2 - y1)
					{
						for (int checkhigh = 1; checkhigh > 0; checkhigh++)
						{
							cout << "���߸߶�Ϊ�����߶�֮��ֵ������ȷ�����κ�����ߵ㡣��ȷ���߶ȴ�������յ�߶Ȳʹ������ߵ�λ������յ�֮��" << endl;
							cout << "�������߸߶�" << endl;
							cin >> high;
							if (high > y2 - y1)
								checkhigh = -10;
						}
					}
				}
				else if (funmodle == 2)
				{
					cout << "�����������" << endl;//���ױ������Ŀ��Ƶ�
					cin >> x3 >> y3 >> z3;
				}

				float x, y, z;//��ֵ
				x = x2 - x1;
				y = y2 - y1;
				z = z2 - z1;
				int i = 0;

				switch (funmodle)//���ɻ�������ģ��
				{
				case 0:
				{
					float x, y, z;//��ֵ
					x = x2 - x1;
					y = y2 - y1;
					z = z2 - z1;

					double a, b, c;//ֱ��ͶӰ
					a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
					b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
					c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

					for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
					{
						cx[i] = k * a;
						cy[i] = k * b;
						cz[i] = k * c;
						i++;
					}
				}
				break;
				case 1:
				{
					if (y1 == y2)
					{
						double x0 = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2)) / 2;
						double a2 = high / pow(x0, 2);//���κ���������ϵ��

						float x, y, z;//��ֵ
						x = x2 - x1;
						y = y2 - y1;
						z = z2 - z1;

						float a, b, c;
						a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
						b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
						c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

						for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
						{
							cx[i] = k * a;
							if (k <= x0)
							{
								cy[i] = k * b + high - a2 * pow(x0 - k, 2);
							}
							else
							{
								cy[i] = k * b + high - a2 * pow(k - x0, 2);
							}
							cz[i] = k * c;
							i++;
						}
					}
					else if (high > (y2 - y1))
					{
						float l = sqrt(pow(x1 - x2, 2) + pow(z1 - z2, 2));//���κ�����ʽ
						float h1 = high - y2 + y1;
						float h2 = y2 - y1;
						if (y2 < y1)
						{
							h1 = high;
							h2 = -1 * h2;
						}

						float x0 = (-2 + sqrt(4 + 4 * (h2 / h1))) / (2 * h2 / (h1 * l));
						float a2 = fabs(h1) / pow(x0, 2);

						float x, y, z;//��ֵ
						x = x2 - x1;
						y = y2 - y1;
						z = z2 - z1;

						float a, c;
						a = x / (sqrt(pow(x, 2) + pow(z, 2)));
						c = z / (sqrt(pow(x, 2) + pow(z, 2)));

						for (float k = 0; k <= (sqrt(pow(x, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
						{
							cx[i] = k * a;
							cz[i] = k * c;
							if (y2 > y1)
							{
								if (k < (l - x0))
									cy[i] = high - a2 * pow(l - x0 - k, 2);
								else
									cy[i] = high - a2 * pow(k - l + x0, 2);
							}
							else
							{
								if (k < x0)
									cy[i] = high - a2 * pow(x0 - k, 2);
								else
									cy[i] = high - a2 * pow(k - x0, 2);
							}
							i++;
						}
					}
				}
				break;
				case 2:
				{
					float x, y, z;//��ֵ
					x = x2 - x1;
					y = y2 - y1;
					z = z2 - z1;

					for (double k = 0; k <= 100000; k += (100000 / (tickall * tickchange)))
					{
						double k2 = k / 100000;
						cx[i] = pow(1 - k2, 2) * x1 + 2 * k2 * (1 - k2) * x3 + pow(k2, 2) * x2 - x1;
						cy[i] = pow(1 - k2, 2) * y1 + 2 * k2 * (1 - k2) * y3 + pow(k2, 2) * y2 - y1;
						cz[i] = pow(1 - k2, 2) * z1 + 2 * k2 * (1 - k2) * z3 + pow(k2, 2) * z2 - z1;
						i++;
					}
				}
				break;
				}

				cout << "�ǶȲ���" << endl;
				float anglell;
				cin >> anglell;
				cout << "����λ" << endl;
				float anglell0;
				cin >> anglell0;
				anglell = (anglell / 180) * 3.1415926535898;
				anglell0 = (anglell0 / 180) * 3.1415926535898;
				cout << "������" << endl;
				float ll;
				cin >> ll;

				float xadd, yadd, zadd;
				float dxp, dyp, dzp;
				float ii = i;
				for (int j = 0; j < i - 1; j++)
				{
					float dxn = cx[j + 1] - cx[j];
					float dyn = cy[j + 1] - cy[j];
					float dzn = cz[j + 1] - cz[j];

					if (j == 0)
					{
						dxp = cx[j + 1] - cx[j];
						dyp = cy[j + 1] - cy[j];
						dzp = cz[j + 1] - cz[j];
					}

					float dx = (dxn + dxp) / 2;
					float dy = (dyn + dyp) / 2;
					float dz = (dzn + dzp) / 2;

					dxp = dxn;
					dyp = dyn;
					dzp = dzn;

					yadd = 0;
					if (i % 2 == 0)
					{
						if (j < (i / 2))
						{
							xadd = (2 * j / ii) * ll * cos(anglell * j + anglell0);
							zadd = (2 * j / ii) * ll * sin(anglell * j + anglell0);
						}
						else if (j == (i / 2))
						{
							xadd = ll * cos(anglell * j + anglell0);
							zadd = ll * sin(anglell * j + anglell0);
						}
						else
						{
							xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j + anglell0);
							zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j + anglell0);
						}
					}
					else
					{
						if (j < ((i + 1) / 2))
						{
							xadd = (2 * j / (ii - 1)) * ll * cos(anglell * j + anglell0);
							zadd = (2 * j / (ii - 1)) * ll * sin(anglell * j + anglell0);
						}
						else
						{
							xadd = (1 - ((2 * j - ii) / ii)) * ll * cos(anglell * j + anglell0);
							zadd = (1 - ((2 * j - ii) / ii)) * ll * sin(anglell * j + anglell0);
						}
					}

					float xaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "x");
					float yaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "y");
					float zaddp = normal_vector_rot(dx, dy, dz, xadd, yadd, zadd, "z");

					cx[j + i + 1] = xaddp;
					cy[j + i + 1] = yaddp;
					cz[j + i + 1] = zaddp;
				}

				string smodule15 = to_string(loop15);
				fname = fname + "p" + smodule15;

				writefunction_m4(i, x, y, z, tickchange, tickall, fname);
			}
			break;
			}

			cout << "�Ƿ����(Y/N)" << endl;
			string loop15n;
			cin >> loop15n;
			if (loop15n == "N" || loop15n == "n")
			{
				string docname = ffname + ".mcfunction";
				ofstream functioncout(docname);
				for (int floop15 = 1; floop15 <= loop15; floop15++)
				{
					string smodule15 = to_string(floop15);
					string finalfunction = ffname + "p" + smodule15;
					functioncout << "function " << finalfunction << endl;
				}
				functioncout.close();
				loop15 = -1;
			}
		}
	}
	break;
	case 16:
	{
		cout << "������ɢ�뾶" << endl;
		float ryks;
		cin >> ryks;
		ryks = (ryks * 2) / 11;
		cout << "������������" << endl;
		float nyks;
		cin >> nyks;
		cout << "������ɢ��(X/Y/Z)" << endl;
		string ksm;
		cin >> ksm;
		cout << "�Ƿ��ɫ����(Y/N)" << endl;
		string cspz;
		cin >> cspz;
		int red1, green1, blue1;
		int pptime;
		if (cspz == "Y" || cspz == "y")
		{
			cout << "����������ɫ" << endl;
			cin >> red1 >> green1 >> blue1;
			cout << "������������" << endl;//���Ӵ���ʱ��
			cin >> pptime;
		}
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		if (ksm == "X" || ksm == "x")
		{
			if (cspz == "Y" || cspz == "y")
			{
				string ffname = fname + ".mcfunction";
				ofstream functioncout(ffname);
				for (float ksy = 0; ksy <= 360; ksy += 360 / nyks)
				{
					float x = ryks * cos(ksy * 3.141592695 / 180);
					float y = ryks * sin(ksy * 3.141592695 / 180);

					functioncout << "particle soy:life_color_particle "
						<< fixed << setprecision(0)
						<< red1 * 65536 + green1 * 256 + blue1
						<< " " << pptime << " 1"
						<< fixed << setprecision(8)
						<< " ~ ~ ~"
						<< " 0 " << x << " " << y
						<< " 0.5"
						<< " 0 force @a" << endl;
				}
				functioncout.close();
			}
			else
			{
				string ffname = fname + ".mcfunction";
				ofstream functioncout(ffname);
				for (float ksy = 0; ksy <= 360; ksy += 360 / nyks)
				{
					float x = ryks * cos(ksy * 3.141592695 / 180);
					float y = ryks * sin(ksy * 3.141592695 / 180);

					functioncout << "particle minecraft:end_rod"
						<< fixed << setprecision(8)
						<< " ~ ~ ~"
						<< " 0 " << x << " " << y
						<< " 0.5"
						<< " 0 force @a" << endl;
				}
				functioncout.close();
			}
		}
		else if (ksm == "Y" || ksm == "y")
		{
			if (cspz == "Y" || cspz == "y")
			{
				string ffname = fname + ".mcfunction";
				ofstream functioncout(ffname);
				for (float ksy = 0; ksy <= 360; ksy += 360 / nyks)
				{
					float x = ryks * cos(ksy * 3.141592695 / 180);
					float y = ryks * sin(ksy * 3.141592695 / 180);

					functioncout << "particle soy:life_color_particle "
						<< fixed << setprecision(0)
						<< red1 * 65536 + green1 * 256 + blue1
						<< " " << pptime << " 1"
						<< fixed << setprecision(8)
						<< " ~ ~ ~"
						<< " " << x << " 0 " << y
						<< " 0.5"
						<< " 0 force @a" << endl;
				}
				functioncout.close();
			}
			else
			{
				string ffname = fname + ".mcfunction";
				ofstream functioncout(ffname);
				for (float ksy = 0; ksy <= 360; ksy += 360 / nyks)
				{
					float x = ryks * cos(ksy * 3.141592695 / 180);
					float y = ryks * sin(ksy * 3.141592695 / 180);

					functioncout << "particle minecraft:end_rod"
						<< fixed << setprecision(8)
						<< " ~ ~ ~"
						<< " " << x << " 0 " << y
						<< " 0.5"
						<< " 0 force @a" << endl;
				}
				functioncout.close();
			}
		}
		else if (ksm == "Z" || ksm == "z")
		{
			if (cspz == "Y" || cspz == "y")
			{
				string ffname = fname + ".mcfunction";
				ofstream functioncout(ffname);
				for (float ksy = 0; ksy <= 360; ksy += 360 / nyks)
				{
					float x = ryks * cos(ksy * 3.141592695 / 180);
					float y = ryks * sin(ksy * 3.141592695 / 180);

					functioncout << "particle soy:life_color_particle "
						<< fixed << setprecision(0)
						<< red1 * 65536 + green1 * 256 + blue1
						<< " " << pptime << " 1"
						<< fixed << setprecision(8)
						<< " ~ ~ ~"
						<< " " << x << " " << y << " 0"
						<< " 0.5"
						<< " 0 force @a" << endl;
				}
				functioncout.close();
			}
			else
			{
				string ffname = fname + ".mcfunction";
				ofstream functioncout(ffname);
				for (float ksy = 0; ksy <= 360; ksy += 360 / nyks)
				{
					float x = ryks * cos(ksy * 3.141592695 / 180);
					float y = ryks * sin(ksy * 3.141592695 / 180);

					functioncout << "particle minecraft:end_rod"
						<< fixed << setprecision(8)
						<< " ~ ~ ~"
						<< " " << x << " " << y << " 0"
						<< " 0.5"
						<< " 0 force @a" << endl;
				}
				functioncout.close();
			}
		}
	}
	break;
	case 17:
	{
		cout << "�������������Բ�뾶" << endl;
		float ryks;
		cin >> ryks;
		cout << "����ÿ����������" << endl;
		float nyks;
		cin >> nyks;
		cout << "������ɢ��(X/Y/Z)" << endl;
		string ksm;
		cin >> ksm;
		cout << "������תʱ��" << endl;
		float dttime;
		cin >> dttime;
		cout << "���벽���Ƕ�" << endl;
		float bjangle;
		cin >> bjangle;
		cout << "�Ƿ��ɫ����(Y/N)" << endl;
		string cspz;
		cin >> cspz;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;

		x1 = (-sqrt(3) / 2) * ryks;
		z1 = -0.5 * ryks;
		z2 = ryks;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;
		double a, b, c;//ֱ��ͶӰ
		a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		int i = 0;
		int count = 0;
		for (double k = 0; count <= nyks; k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / nyks))
		{
			cx[i] = k * a + (-sqrt(3) / 2) * ryks;
			cy[i] = k * b;
			cz[i] = k * c + -0.5 * ryks;
			i++;
			count++;
		}

		x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;
		z1 = ryks;
		x2 = (sqrt(3) / 2) * ryks;
		z2 = -0.5 * ryks;

		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;
		a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		count = 0;
		for (double k = 0; count <= nyks; k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / nyks))
		{
			cx[i] = k * a;
			cy[i] = k * b;
			cz[i] = k * c + ryks;
			i++;
			count++;
		}

		x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;
		x1 = (-sqrt(3) / 2) * ryks;
		z1 = -0.5 * ryks;
		x2 = (sqrt(3) / 2) * ryks;
		z2 = -0.5 * ryks;

		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;
		a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		count = 0;
		for (double k = 0; count <= nyks; k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / nyks))
		{
			cx[i] = k * a + (-sqrt(3) / 2) * ryks;
			cy[i] = k * b;
			cz[i] = k * c + -0.5 * ryks;
			i++;
			count++;
		}

		count = i - 1;

		for (float rotloop = 1; rotloop < dttime; rotloop++)
		{
			for (int j = 0; j <= count; j++)
			{
				float angle, l;
				angle = atan2(cz[j], cx[j]);
				angle += bjangle * rotloop * 3.1415926 / 180.0;
				l = sqrt(pow(cx[j], 2) + pow(cz[j], 2)) * ((dttime - rotloop) / dttime);
				cx[i] = l * cos(angle);
				cz[i] = l * sin(angle);
				i++;
			}
		}

		if (ksm == "X" || ksm == "x")
			for (int changeksm = 0; changeksm <= i; changeksm++)
			{
				float changeksmm;
				changeksmm = cx[changeksm];
				cx[changeksm] = cy[changeksm];
				cy[changeksm] = changeksmm;
			}
		else if (ksm == "Z" || ksm == "z")
			for (int changeksm = 0; changeksm <= i; changeksm++)
			{
				float changeksmm;
				changeksmm = cz[changeksm];
				cz[changeksm] = cy[changeksm];
				cy[changeksm] = changeksmm;
			}

		if (cspz == "Y" || cspz == "y")
			writefunction_m7(i, 0, 0, 0, 3 * (nyks + 1), dttime, fname);
		else
			writefunction_m6(i, 0, 0, 0, 3 * (nyks + 1), dttime, fname);

	}
	break;
	case 18:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		float tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		float tickall;
		cin >> tickall;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		float L1 = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		float L2 = sqrt(pow(x, 2) + pow(z, 2));

		float xx, yy, zz;//��ֵ
		xx = -sin(atan2(y, L2)) * L1 * cos(atan2(z, x));
		yy = L1 * cos(atan2(y, L2));
		zz = -sin(atan2(y, L2)) * L1 * sin(atan2(z, x));

		double a, b, c;//ֱ��ͶӰ
		a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		double aa, bb, cc;//ֱ��ͶӰ
		aa = xx / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		bb = yy / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		cc = zz / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		int i = 0;

		for (double k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / ((float)tickall * tickchange)))
		{
			if (2 * k < (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))))
			{
				cx[i] = k * a + k * aa;
				cy[i] = k * b + k * bb;
				cz[i] = k * c + k * cc;
				i++;
				cx[i] = k * a - k * aa;
				cy[i] = k * b - k * bb;
				cz[i] = k * c - k * cc;
				i++;
			}
			else
			{
				cx[i] = k * a + (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) - k) * aa;
				cy[i] = k * b + (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) - k) * bb;
				cz[i] = k * c + (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) - k) * cc;
				i++;
				cx[i] = k * a - (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) - k) * aa;
				cy[i] = k * b - (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) - k) * bb;
				cz[i] = k * c - (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) - k) * cc;
				i++;
			}
		}

		i--;
		writefunction_m1(i, x, y, z, 2 * tickchange, tickall, fname);
	}
	break;
	case 19:
	{
		float x1, y1, z1;
		float x2, y2, z2;
		float x3, y3, z3;//Բ��
		float x4, y4, z4;//������
		cout << "ƽ��Soma3����ȷ������yֵ��ͬ" << endl;
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		float tickchange;
		cin >> tickchange;
		float tickchange2 = floor(tickchange / (2.0 * 3.1415926535));
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;
		cout << "�����������" << endl;
		cin >> x1 >> y1 >> z1;

		cout << "������̺�ʱ" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall = 0, ticki = 0;
		cin >> ticki;
		tickall += ticki;
		cout << "�����������" << endl;
		cin >> x2 >> y2 >> z2;
		cout << "�Ƿ����(Y/N)" << endl;
		string ifloopp;
		cin >> ifloopp;

		x3 = (x1 + x2) / 2;
		z3 = (z1 + z2) / 2;

		float L12, L13, L23, LL14, LL12, LL42;
		L12 = sqrt(pow(x2 - x1, 2) + pow(z2 - z1, 2));
		L13 = sqrt(pow(x3 - x1, 2) + pow(z3 - z1, 2));
		L23 = sqrt(pow(x3 - x2, 2) + pow(z3 - z2, 2));
		float theta, theta2;//����ת��
		theta = acos((pow(L13, 2) + pow(L23, 2) - pow(L12, 2)) / (2.0 * L13 * L23));

		float jx, jy, jz;
		float jx2, jy2, jz2;
		jx = x1 - x3;
		jz = z1 - z3;
		float anglej0, anglej1;
		anglej0 = atan2(jz, jx);

		tickchange = floor(sqrt(pow(x3 - x1, 2) + pow(z3 - z1, 2))) * tickchange2;

		int i = 0;
		float countloop = 1;

		for (float k = 0; countloop <= tickchange * ticki; k += theta / ((tickchange * ticki) - 1))
		{
			cx[i] = (x3 - x1) + 0.5 * L12 * cos(anglej0 + k);
			cy[i] = 0;
			cz[i] = (z3 - z1) + 0.5 * L12 * sin(anglej0 + k);
			flexible_argument[i] = floor(sqrt(pow(x3 - x1, 2) + pow(z3 - z1, 2)));//�뾶
			i++;
			countloop++;
		}

		int ifloop = 0;
		if (ifloopp == "N" || ifloopp == "n")
			ifloop = 1;

		string docname = fname + "_tp_0.mcfunction";
		string docname2 = fname + "_tp_1";
		ofstream functioncout0(docname);
		functioncout0 << "schedule function minecraft:" << docname2 << " " << ticki << "t";
		functioncout0.close();

		int looptp = 1;

		while (ifloop == 0)
		{
			cout << "������̺�ʱ" << endl;//�ڶ���tick��ִ��ȫ��ָ��
			ticki = 0;
			cin >> ticki;
			tickall += ticki;

			docname = fname + "_tp_" + to_string(looptp) + ".mcfunction";
			docname2 = fname + "_tp_" + to_string(looptp + 1);
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << "] at @s run tp @s ~" << x2 - x1 << " ~" << y2 - y1 << " ~" << z2 - z1 << endl;
			functioncout << "schedule function minecraft:" << docname2 << " " << ticki << "t";
			functioncout.close();

			x1 = x2;
			y1 = y2;
			z1 = z2;

			cout << "�����������" << endl;
			cin >> x2 >> y2 >> z2;
			cout << "�Ƿ����(Y/N)" << endl;
			cin >> ifloopp;

			x4 = x1 + cx[i - 1] - cx[i - 2];
			y4 = y1 + cy[i - 1] - cy[i - 2];
			z4 = z1 + cz[i - 1] - cz[i - 2];

			float a1, b1, c1;

			a1 = x1 * (z2 - z4) - z1 * (x2 - x4) + x2 * z4 - x4 * z2;
			b1 = (x1 * x1 + z1 * z1) * (z4 - z2) + (x2 * x2 + z2 * z2) * (z1 - z4) + (x4 * x4 + z4 * z4) * (z2 - z1);
			c1 = (x1 * x1 + z1 * z1) * (x2 - x4) + (x2 * x2 + z2 * z2) * (x4 - x1) + (x4 * x4 + z4 * z4) * (x1 - x2);

			x3 = -b1 / (2.0 * a1);
			y3 = y1;
			z3 = -c1 / (2.0 * a1);

			L12 = sqrt(pow(x2 - x1, 2) + pow(z2 - z1, 2));
			L13 = sqrt(pow(x3 - x1, 2) + pow(z3 - z1, 2));
			L23 = sqrt(pow(x3 - x2, 2) + pow(z3 - z2, 2));
			theta = acos((pow(L13, 2) + pow(L23, 2) - pow(L12, 2)) / (2.0 * L13 * L23));//����ת��

			jx = x1 - x3;
			jy = y1 - y3;
			jz = z1 - z3;
			anglej0 = atan2(jz, jx);//��ʼ��

			jx2 = x4 - x3;
			jy2 = y4 - y3;
			jz2 = z4 - z3;
			anglej1 = atan2(jz2, jx2);//��ʼ��2

			LL14 = sqrt(pow(x4 - x1, 2) + pow(z4 - z1, 2));
			LL12 = sqrt(pow(x2 - x1, 2) + pow(z2 - z1, 2));
			LL42 = sqrt(pow(x2 - x4, 2) + pow(z2 - z4, 2));
			theta2 = acos((pow(LL14, 2) + pow(LL12, 2) - pow(LL42, 2)) / (2.0 * LL14 * LL12));//����ת��

			if (2 * theta2 >= 3.1415926535)
				theta = 2.0 * 3.1415926535 - theta;

			tickchange = floor(sqrt(pow(x3 - x1, 2) + pow(z3 - z1, 2))) * tickchange2;

			countloop = 1;

			if (anglej1 > anglej0)
			{
				for (float k = 0; countloop <= tickchange * ticki; k += (theta / (tickchange * ticki - 1)))
				{
					cx[i] = (x3 - x1) + L13 * cos(anglej0 + k);
					cy[i] = 0;
					cz[i] = (z3 - z1) + L13 * sin(anglej0 + k);
					flexible_argument[i] = floor(sqrt(pow(x3 - x1, 2) + pow(z3 - z1, 2)));//�뾶
					i++;
					countloop++;
				}
			}
			else
			{
				for (float k = 0; countloop <= tickchange * ticki; k += (theta / (tickchange * ticki - 1)))
				{
					cx[i] = (x3 - x1) + L13 * cos(anglej0 - k);
					cy[i] = 0;
					cz[i] = (z3 - z1) + L13 * sin(anglej0 - k);
					flexible_argument[i] = floor(sqrt(pow(x3 - x1, 2) + pow(z3 - z1, 2)));//�뾶
					i++;
					countloop++;
				}
			}

			if (ifloopp == "N" || ifloopp == "n")
				ifloop = 1;
			looptp++;
		}

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		writefunction_m8(i + 1 - looptp, x, y, z, tickchange2, tickall, fname);

		docname = fname + ".mcfunction";//������
		remove(docname.c_str());
		ofstream functioncout1(docname);
		functioncout1 << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
		functioncout1 << "function minecraft:" << fname << "_0" << endl;
		functioncout1 << "function minecraft:" << fname << "_tp_0" << endl;
		functioncout1.close();
	}
	break;
	case 20:
	{
		float x1, y1, z1;
		float x2, y2, z2;
		float x3, y3, z3;//Բ��
		float x4, y4, z4;//������
		cout << "���������ܶ�" << endl;//ÿtickִ�ж���ָ��
		float tickchange;
		cin >> tickchange;
		float tickchange2 = floor(tickchange / (2.0 * 3.1415926535));
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;
		cout << "�����������" << endl;
		cin >> x1 >> y1 >> z1;

		cout << "������̺�ʱ" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall = 0, ticki = 0;
		cin >> ticki;
		tickall += ticki;
		cout << "�����������" << endl;
		cin >> x2 >> y2 >> z2;
		cout << "�Ƿ����(Y/N)" << endl;
		string ifloopp;
		cin >> ifloopp;

		x3 = (x1 + x2) / 2;
		y3 = (y1 + y2) / 2;
		z3 = (z1 + z2) / 2;

		float L12, L13, L23, Lxz;
		L12 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
		L13 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2));
		L23 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2) + pow(z3 - z2, 2));
		Lxz = sqrt(pow(x2 - x1, 2) + pow(z2 - z1, 2));
		float theta;//����ת��
		theta = acos((pow(L13, 2) + pow(L23, 2) - pow(L12, 2)) / (2.0 * L13 * L23));

		float jx, jy, jz;
		float jx2, jy2, jz2;
		jx = x1 - x3;
		jy = y1 - y3;
		jz = z1 - z3;
		float anglej0, anglej1;
		anglej0 = atan2(jz, jx);

		tickchange = floor(sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2)) * tickchange2);

		int i = 0;
		float countloop = 1;

		for (float k = 0; countloop <= tickchange * ticki; k += theta / (tickchange * ticki - 1))
		{
			cx[i] = (x3 - x1) + 0.5 * Lxz * cos(anglej0 + k);
			cy[i] = (k / theta) * (y2 - y1);
			cz[i] = (z3 - z1) + 0.5 * Lxz * sin(anglej0 + k);
			flexible_argument[i] = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2));//�뾶
			i++;
			countloop++;
		}

		int ifloop = 0;
		if (ifloopp == "N" || ifloopp == "n")
			ifloop = 1;

		string docname = fname + "_tp_0.mcfunction";
		string docname2 = fname + "_tp_1";
		ofstream functioncout0(docname);
		functioncout0 << "schedule function minecraft:" << docname2 << " " << ticki << "t";
		functioncout0.close();

		int looptp = 1;

		while (ifloop == 0)
		{
			cout << "������̺�ʱ" << endl;//�ڶ���tick��ִ��ȫ��ָ��
			ticki = 0;
			cin >> ticki;
			tickall += ticki;

			docname = fname + "_tp_" + to_string(looptp) + ".mcfunction";
			docname2 = fname + "_tp_" + to_string(looptp + 1);
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << "] at @s run tp @s ~" << x2 - x1 << " ~" << y2 - y1 << " ~" << z2 - z1 << endl;
			functioncout << "schedule function minecraft:" << docname2 << " " << ticki << "t";
			functioncout.close();

			x1 = x2;
			y1 = y2;
			z1 = z2;

			cout << "�����������" << endl;
			cin >> x2 >> y2 >> z2;
			cout << "�Ƿ����(Y/N)" << endl;
			cin >> ifloopp;

			x4 = x1 + cx[i - 1] - cx[i - 2];
			y4 = y1 + cy[i - 1] - cy[i - 2];
			z4 = z1 + cz[i - 1] - cz[i - 2];

			float a1, b1, c1, d1;
			float a2, b2, c2, d2;
			float a3, b3, c3, d3;

			a1 = (y1 * z2 - y2 * z1 - y1 * z4 + y4 * z1 + y2 * z4 - y4 * z2);
			b1 = -(x1 * z2 - x2 * z1 - x1 * z4 + x4 * z1 + x2 * z4 - x4 * z2);
			c1 = (x1 * y2 - x2 * y1 - x1 * y4 + x4 * y1 + x2 * y4 - x4 * y2);
			d1 = -(x1 * y2 * z4 - x1 * y4 * z2 - x2 * y1 * z4 + x2 * y4 * z1 + x4 * y1 * z2 - x4 * y2 * z1);
			a2 = 2.0 * (x2 - x1);
			b2 = 2.0 * (y2 - y1);
			c2 = 2.0 * (z2 - z1);
			d2 = x1 * x1 + y1 * y1 + z1 * z1 - x2 * x2 - y2 * y2 - z2 * z2;
			a3 = 2.0 * (x4 - x1);
			b3 = 2.0 * (y4 - y1);
			c3 = 2.0 * (z4 - z1);
			d3 = x1 * x1 + y1 * y1 + z1 * z1 - x4 * x4 - y4 * y4 - z4 * z4;

			x3 = -(b1 * c2 * d3 - b1 * c3 * d2 - b2 * c1 * d3 + b2 * c3 * d1 + b3 * c1 * d2 - b3 * c2 * d1) / (a1 * b2 * c3 - a1 * b3 * c2 - a2 * b1 * c3 + a2 * b3 * c1 + a3 * b1 * c2 - a3 * b2 * c1);
			y3 = (a1 * c2 * d3 - a1 * c3 * d2 - a2 * c1 * d3 + a2 * c3 * d1 + a3 * c1 * d2 - a3 * c2 * d1) / (a1 * b2 * c3 - a1 * b3 * c2 - a2 * b1 * c3 + a2 * b3 * c1 + a3 * b1 * c2 - a3 * b2 * c1);
			z3 = -(a1 * b2 * d3 - a1 * b3 * d2 - a2 * b1 * d3 + a2 * b3 * d1 + a3 * b1 * d2 - a3 * b2 * d1) / (a1 * b2 * c3 - a1 * b3 * c2 - a2 * b1 * c3 + a2 * b3 * c1 + a3 * b1 * c2 - a3 * b2 * c1);

			float xzx, xzz;
			xzx = normal_vector_rot(-a1, -b1, -c1, 1, 0, 0, "x");
			xzz = normal_vector_rot(-a1, -b1, -c1, 1, 0, 0, "z");


			L12 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
			L13 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2));
			L23 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2) + pow(z3 - z2, 2));
			Lxz = sqrt(pow(x3 - x1, 2) + pow(z3 - z1, 2));
			theta = acos((pow(L13, 2) + pow(L23, 2) - pow(L12, 2)) / (2.0 * L13 * L23));//����ת��

			jx = x1 - x3;
			jy = y1 - y3;
			jz = z1 - z3;
			anglej0 = acos((jx * xzx + jz * xzz) / sqrt(pow(jx, 2) + pow(jy, 2) + pow(jz, 2)));//��ʼ��

			jx2 = x4 - x3;
			jy2 = y4 - y3;
			jz2 = z4 - z3;
			anglej1 = acos((jx2 * xzx + jz2 * xzz) / sqrt(pow(jx2, 2) + pow(jy2, 2) + pow(jz2, 2)));//��ʼ��2

			if (anglej1 < anglej0)
				theta = 2.0 * 3.1415926535 - theta;

			tickchange = floor(sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2)) * tickchange2);

			countloop = 1;

			if (anglej1 > anglej0)
			{
				for (float k = 0; countloop <= tickchange * ticki; k += (theta / (tickchange * ticki - 1)))
				{
					cx[i] = (x3 - x1) + normal_vector_rot(-a1, -b1, -c1, Lxz * cos(anglej0 + k), 0, Lxz * sin(anglej0 + k), "x");
					cy[i] = (y3 - y1) + normal_vector_rot(-a1, -b1, -c1, Lxz * cos(anglej0 + k), 0, Lxz * sin(anglej0 + k), "y");
					cz[i] = (z3 - z1) + normal_vector_rot(-a1, -b1, -c1, Lxz * cos(anglej0 + k), 0, Lxz * sin(anglej0 + k), "z");
					flexible_argument[i] = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2));//�뾶
					i++;
					countloop++;
				}
			}
			else
			{
				for (float k = 0; countloop <= tickchange * ticki; k += (theta / (tickchange * ticki - 1)))
				{
					cx[i] = (x3 - x1) - normal_vector_rot(a1, b1, c1, Lxz * cos(anglej0 - k), 0, Lxz * sin(anglej0 - k), "x");
					cy[i] = (y3 - y1) - normal_vector_rot(a1, b1, c1, Lxz * cos(anglej0 - k), 0, Lxz * sin(anglej0 - k), "y");
					cz[i] = (z3 - z1) - normal_vector_rot(a1, b1, c1, Lxz * cos(anglej0 - k), 0, Lxz * sin(anglej0 - k), "z");
					flexible_argument[i] = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2) + pow(z3 - z1, 2));//�뾶
					i++;
					countloop++;
				}
			}

			if (ifloopp == "N" || ifloopp == "n")
				ifloop = 1;
			looptp++;
		}

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		writefunction_m8(i + 1 - looptp, x, y, z, tickchange2, tickall, fname);

		docname = fname + ".mcfunction";//������
		remove(docname.c_str());
		ofstream functioncout1(docname);
		functioncout1 << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
		functioncout1 << "function minecraft:" << fname << "_0" << endl;
		functioncout1 << "function minecraft:" << fname << "_tp_0" << endl;
		functioncout1.close();
	}
	break;
	case 501:
	{
		cout << "ѡ��̬����:" << endl
			<< "1.���֣��������½���" << endl
			<< "2.���֣���ֹ�޶�̬��" << endl
			<< "3.ƽ�ƣ�����ֱ��ģʽ��" << endl
			<< "4.��ɢ����ԭ�������ܣ�" << endl
			<< "5.���죨����ȫ��ɢ��" << endl
			<< "6.��ת����ԭ��Ϊ���ģ�" << endl
			<< "7.�ƶ����Զ���·����" << endl
			<< "8.�ද̬���" << endl
			<< "ѡ����:";
		int module_choose;
		cin >> module_choose;

		float key_px1, key_px2, key_px3, key_px4;//�������ĸ��ؼ���
		float key_py1, key_py2, key_py3, key_py4;
		float key_pz1, key_pz2, key_pz3, key_pz4;

		key_px1 = 0.5;
		key_px2 = -0.5;
		key_px3 = 0.5;
		key_px4 = -0.5;

		key_py1 = 0.5;
		key_py2 = 0.5;
		key_py3 = -0.5;
		key_py4 = -0.5;

		key_pz1 = 0.5;
		key_pz2 = -0.5;
		key_pz3 = -0.5;
		key_pz4 = 0.5;

		switch (module_choose)
		{
		case 1:
		case 2:
		case 3:
		{
			cout << "�������С:";
			float size;
			cin >> size;
			if (size == 0)
				size = 1;
			cout << "������ܶ�:";
			float pmd;
			cin >> pmd;
			if (pmd == 0)
				pmd = 1;

			float deta_k = size / (size * pmd);

			int i = 0;

			{
				cx[i] = key_px1 * size;//����1
				cy[i] = key_py1 * size;
				cz[i] = key_pz1 * size;
				i++;
				cx[i] = cx[i - 1] - deta_k;
				cy[i] = cy[i - 1];
				cz[i] = cz[i - 1];
				i++;
				cx[i] = cx[i - 2];
				cy[i] = cy[i - 2];
				cz[i] = cz[i - 2] - deta_k;
				i++;
				cx[i] = cx[i - 3];
				cy[i] = cy[i - 3] - deta_k;
				cz[i] = cz[i - 3];
				i++;

				for (float k = deta_k; k < size; k += deta_k)//����1������������
				{
					cx[i] = cx[i - 3] - deta_k;
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3];
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3] - deta_k;
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3] - deta_k;
					cz[i] = cz[i - 3];
					i++;
				}

				cx[i] = key_px2 * size;//����2
				cy[i] = key_py2 * size;
				cz[i] = key_pz2 * size;
				i++;
				cx[i] = cx[i - 1] + deta_k;
				cy[i] = cy[i - 1];
				cz[i] = cz[i - 1];
				i++;
				cx[i] = cx[i - 2];
				cy[i] = cy[i - 2];
				cz[i] = cz[i - 2] + deta_k;
				i++;
				cx[i] = cx[i - 3];
				cy[i] = cy[i - 3] - deta_k;
				cz[i] = cz[i - 3];
				i++;

				for (float k = deta_k; k < size; k += deta_k)//����2������������
				{
					cx[i] = cx[i - 3] + deta_k;
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3];
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3] + deta_k;
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3] - deta_k;
					cz[i] = cz[i - 3];
					i++;
				}

				cx[i] = key_px3 * size;//����3
				cy[i] = key_py3 * size;
				cz[i] = key_pz3 * size;
				i++;
				cx[i] = cx[i - 1] - deta_k;
				cy[i] = cy[i - 1];
				cz[i] = cz[i - 1];
				i++;
				cx[i] = cx[i - 2];
				cy[i] = cy[i - 2];
				cz[i] = cz[i - 2] + deta_k;
				i++;
				cx[i] = cx[i - 3];
				cy[i] = cy[i - 3] + deta_k;
				cz[i] = cz[i - 3];
				i++;

				for (float k = deta_k; k < size; k += deta_k)//����3������������
				{
					cx[i] = cx[i - 3] - deta_k;
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3];
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3] + deta_k;
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3] + deta_k;
					cz[i] = cz[i - 3];
					i++;
				}

				cx[i] = key_px4 * size;//����4
				cy[i] = key_py4 * size;
				cz[i] = key_pz4 * size;
				i++;
				cx[i] = cx[i - 1] + deta_k;
				cy[i] = cy[i - 1];
				cz[i] = cz[i - 1];
				i++;
				cx[i] = cx[i - 2];
				cy[i] = cy[i - 2];
				cz[i] = cz[i - 2] - deta_k;
				i++;
				cx[i] = cx[i - 3];
				cy[i] = cy[i - 3] + deta_k;
				cz[i] = cz[i - 3];
				i++;

				for (float k = deta_k; k < size; k += deta_k)//����4������������
				{
					cx[i] = cx[i - 3] + deta_k;
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3];
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3] - deta_k;
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3] + deta_k;
					cz[i] = cz[i - 3];
					i++;
				}
			}

			if (module_choose == 1)
			{
				basic_rotate(i);
				writefunction_m21(i);
			}
			else if (module_choose == 2)
			{
				basic_rotate(i);
				writefunction_m22(i);
			}
			else if (module_choose == 3)
			{
				basic_rotate(i);
				writefunction_m23(i);
			}
		}
		break;
		case 4:
		{
			cout << "������ܶ�:";
			float pmd;
			cin >> pmd;
			if (pmd == 0)
				pmd = 1;

			float deta_k = 1 / pmd;

			int i = 0;

			{
				cx[i] = key_px1;//����1
				cy[i] = key_py1;
				cz[i] = key_pz1;
				i++;
				cx[i] = cx[i - 1] - deta_k;
				cy[i] = cy[i - 1];
				cz[i] = cz[i - 1];
				i++;
				cx[i] = cx[i - 2];
				cy[i] = cy[i - 2];
				cz[i] = cz[i - 2] - deta_k;
				i++;
				cx[i] = cx[i - 3];
				cy[i] = cy[i - 3] - deta_k;
				cz[i] = cz[i - 3];
				i++;

				for (float k = deta_k; k < 1; k += deta_k)//����1������������
				{
					cx[i] = cx[i - 3] - deta_k;
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3];
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3] - deta_k;
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3] - deta_k;
					cz[i] = cz[i - 3];
					i++;
				}

				cx[i] = key_px2;//����2
				cy[i] = key_py2;
				cz[i] = key_pz2;
				i++;
				cx[i] = cx[i - 1] + deta_k;
				cy[i] = cy[i - 1];
				cz[i] = cz[i - 1];
				i++;
				cx[i] = cx[i - 2];
				cy[i] = cy[i - 2];
				cz[i] = cz[i - 2] + deta_k;
				i++;
				cx[i] = cx[i - 3];
				cy[i] = cy[i - 3] - deta_k;
				cz[i] = cz[i - 3];
				i++;

				for (float k = deta_k; k < 1; k += deta_k)//����2������������
				{
					cx[i] = cx[i - 3] + deta_k;
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3];
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3] + deta_k;
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3] - deta_k;
					cz[i] = cz[i - 3];
					i++;
				}

				cx[i] = key_px3;//����3
				cy[i] = key_py3;
				cz[i] = key_pz3;
				i++;
				cx[i] = cx[i - 1] - deta_k;
				cy[i] = cy[i - 1];
				cz[i] = cz[i - 1];
				i++;
				cx[i] = cx[i - 2];
				cy[i] = cy[i - 2];
				cz[i] = cz[i - 2] + deta_k;
				i++;
				cx[i] = cx[i - 3];
				cy[i] = cy[i - 3] + deta_k;
				cz[i] = cz[i - 3];
				i++;

				for (float k = deta_k; k < 1; k += deta_k)//����3������������
				{
					cx[i] = cx[i - 3] - deta_k;
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3];
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3] + deta_k;
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3] + deta_k;
					cz[i] = cz[i - 3];
					i++;
				}

				cx[i] = key_px4;//����4
				cy[i] = key_py4;
				cz[i] = key_pz4;
				i++;
				cx[i] = cx[i - 1] + deta_k;
				cy[i] = cy[i - 1];
				cz[i] = cz[i - 1];
				i++;
				cx[i] = cx[i - 2];
				cy[i] = cy[i - 2];
				cz[i] = cz[i - 2] - deta_k;
				i++;
				cx[i] = cx[i - 3];
				cy[i] = cy[i - 3] + deta_k;
				cz[i] = cz[i - 3];
				i++;

				for (float k = deta_k; k < 1; k += deta_k)//����4������������
				{
					cx[i] = cx[i - 3] + deta_k;
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3];
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3];
					cz[i] = cz[i - 3] - deta_k;
					i++;
					cx[i] = cx[i - 3];
					cy[i] = cy[i - 3] + deta_k;
					cz[i] = cz[i - 3];
					i++;
				}
			}

			basic_rotate(i);
			writefunction_m24(i);
		}
		break;
		}
	}
	break;
	case 1000:
	{
		cout << "�����������:";
		string funname;
		cin >> funname;

		GdiplusStartupInput gdiplusstartupinput;
		ULONG_PTR gdiplustoken;
		GdiplusStartup(&gdiplustoken, &gdiplusstartupinput, nullptr);

		TCHAR szBuffer[MAX_PATH] = { 0 };
		OPENFILENAME ofn = { 0 };
		ofn.lStructSize = sizeof(ofn);
		ofn.lpstrFilter = (L"Jpg�ļ�(*.jpg)\0*.jpg\0Png�ļ�(*.png)\0*.png\0Bmp�ļ�(*.bmp)\0*.bmp\0�����ļ�(*.*)\0*.*\0");//Ҫѡ����ļ���׺   
		ofn.lpstrFile = szBuffer;//����ļ��Ļ�����   
		ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
		ofn.nFilterIndex = 0;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//��־����Ƕ�ѡҪ����OFN_ALLOWMULTISELECT  
		BOOL filename = GetOpenFileName(&ofn);

		wstring infilename = szBuffer;
		string outfilename = funname + ".mcfunction";
		//��ͼƬ
		cout << "��ȡ�ļ���..." << endl;
		Bitmap* bmp = new Bitmap(infilename.c_str());
		UINT height = bmp->GetHeight();
		UINT width = bmp->GetWidth();
		Color color;

		cout << "ͼƬ���:" << width << " ͼƬ�߶�:" << height << endl;
		cout << "��ѡ�� �Ҷȣ�1���� ��ɫ��2���� ��̬�Ҷȣ�3���� ��̬��ɫ��4��ģʽ:";
		int picturec;
		cin >> picturec;

		char pp;//�Ƿ�ݵ���ƿƿ��lolitaȺ��
		int pptime;//ƿƿ����ʱ��
		int dtlx;//��̬���� 
		int dths;//��̬��ʱ

		if (picturec == 1 || picturec == 3)
		{
			cout << "�Ƿ�ʹ��ƿ��mod�������ӻ�����ʱ��(Y/N):";
			cin >> pp;
			if (pp == 'Y' || pp == 'y')
			{
				cout << "�������ʱ��:";
				cin >> pptime;
			}
			if (picturec == 3)
			{
				cout << "��̬�����б�:" << endl
					<< "1.���ϵ��½��� 2.���µ��Ͻ��� 3.�����ҽ��� 4.���ҵ����� 5.����������ɢ 6.����������ɢ" << endl << "ѡ��̬����:";
				cin >> dtlx;
				cout << "�����붯̬��ʱ:";
				cin >> dths;
			}
		}
		else if (picturec == 2 || picturec == 4)
		{
			cout << "�����ܻ���ƿ��mod" << endl;
			cout << "�������ʱ��:";
			cin >> pptime;
			if (picturec == 4)
			{
				cout << "��̬�����б�:" << endl
					<< "1.���ϵ��½��� 2.���µ��Ͻ��� 3.�����ҽ��� 4.���ҵ����� 5.����������ɢ 6.����������ɢ" << endl << "ѡ��̬����:";
				cin >> dtlx;
				cout << "�����붯̬��ʱ:";
				cin >> dths;
			}
		}
		cout << "����������..." << endl;

		switch (picturec)
		{
		case 1:
		{
			Color color;
			ofstream fout(outfilename.c_str());

			for (float y = 0; y < height; y++)
				for (float x = 0; x < width; x++)
				{
					bmp->GetPixel(x, y, &color);
					int red = (int)color.GetRed();
					int green = (int)color.GetGreen();
					int blue = (int)color.GetBlue();
					int alpha = (int)color.GetAlpha();
					if (red < 127 && green < 127 && blue < 127)
					{

						if (pp == 'Y' || pp == 'y')
						{
							fout << "particle soy:life_end_rod " << pptime << " 1 ~ ~-" << y / 8 << " ~" << x / 8 << " 0 0 0 0 0 force @a" << endl;
						}
						else
							fout << "particle minecraft:end_rod ~ ~-" << y / 8 << " ~" << x / 8 << " 0 0 0 0 0 force @a" << endl;
					}
				}

			fout.close();
		}
		break;
		case 2:
		{
			Color color;
			ofstream fout(outfilename.c_str());

			for (float y = 0; y < height; y++)
				for (float x = 0; x < width; x++)
				{
					bmp->GetPixel(x, y, &color);
					int red = (int)color.GetRed();
					int green = (int)color.GetGreen();
					int blue = (int)color.GetBlue();
					int alpha = (int)color.GetAlpha();
					if (alpha == 255)
						fout << "particle soy:life_color_particle " << red * 65536 + green * 256 + blue
						<< " " << pptime << " 1 ~ ~-" << y / 8 << " ~" << x / 8 << " 0 0 0 0 0 force @a" << endl;
				}

			fout.close();
		}
		break;
		case 3:
		{
			switch (dtlx)
			{
			case 1:
			{
				float tim = time(0);
				int ydt = 0;
				int dtjs;
				for (dtjs = 0; dtjs <= dths; dtjs++)
				{
					string dtjss = to_string(dtjs);
					string outfilenameplus = funname + "_" + dtjss + ".mcfunction";
					ofstream fout(outfilenameplus.c_str());
					int ydtt = ydt;

					for (float y = ydt; y < ydtt + floor(height / dths); y++)
					{
						for (float x = 0; x < width; x++)
						{
							bmp->GetPixel(x, y, &color);
							int red = (int)color.GetRed();
							int green = (int)color.GetGreen();
							int blue = (int)color.GetBlue();
							int alpha = (int)color.GetAlpha();

							if (red < 127 && green < 127 && blue < 127)
							{

								if (pp == 'Y' || pp == 'y')
								{
									fout << "execute as @e[type=minecraft:armor_stand,tag=" << funname << ",tag=" << tim << "] at @s run "
										<< "particle soy:life_end_rod " << pptime << " 1 ~" << x / 8 << " ~-" << y / 8 << " ~ 0 0 0 0 0 force @a" << endl;
								}
								else
									fout << "execute as @e[type=minecraft:armor_stand,tag=" << funname << ",tag=" << tim << "] at @s run "
									<< "particle minecraft:end_rod ~" << x / 8 << " ~-" << y / 8 << " ~ 0 0 0 0 0 force @a" << endl;
							}
						}
						ydt++;
					}
					dtjss = to_string(dtjs + 1);
					outfilenameplus = funname + "_" + dtjss;
					fout << "schedule function minecraft:" << outfilenameplus << " 1t";
					fout.close();
				}

				string dtjss = to_string(dtjs);//���һ���ļ����
				string outfilenameplus = funname + "_" + dtjss + ".mcfunction";
				ofstream fout(outfilenameplus.c_str());
				for (float y = ydt; y < height; y++)
				{
					for (float x = 0; x < width; x++)
					{
						bmp->GetPixel(x, y, &color);
						int red = (int)color.GetRed();
						int green = (int)color.GetGreen();
						int blue = (int)color.GetBlue();
						int alpha = (int)color.GetAlpha();

						if (red < 127 && green < 127 && blue < 127)
						{

							if (pp == 'Y' || pp == 'y')
							{
								fout << "execute as @e[type=minecraft:armor_stand,tag=" << funname << ",tag=" << tim << "] at @s run "
									<< "particle soy:life_end_rod " << pptime << " 1 ~" << x / 8 << " ~-" << y / 8 << " ~ 0 0 0 0 0 force @a" << endl;
							}
							else
								fout << "execute as @e[type=minecraft:armor_stand,tag=" << funname << ",tag=" << tim << "] at @s run "
								<< "particle minecraft:end_rod ~" << x / 8 << " ~-" << y / 8 << " ~ 0 0 0 0 0 force @a" << endl;
						}
					}

				}
				fout << "kill @e[type=minecraft:armor_stand,tag=" << funname << ",tag=" << tim << "]";
				fout.close();

				outfilenameplus = funname + ".mcfunction";//������
				ofstream fout2(outfilenameplus.c_str());
				fout2 << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << funname << "\",\"" << tim << "\"],Invisible:1,Marker:1}" << endl;
				fout2 << "function minecraft:" << funname << "_0";
				fout2.close();
			}
			break;
			}
		}
		break;
		case 4:
		{
			Color color;
			ofstream fout(outfilename.c_str());

			for (float y = 0; y < height; y++)
				for (float x = 0; x < width; x++)
				{
					bmp->GetPixel(x, y, &color);
					int red = (int)color.GetRed();
					int green = (int)color.GetGreen();
					int blue = (int)color.GetBlue();
					int alpha = (int)color.GetAlpha();
					if (alpha == 255)
						fout << "particle soy:life_color_particle " << red * 65536 + green * 256 + blue
						<< " " << pptime << " 1 ~" << x / 8 << " ~-" << y / 8 << " ~ 0 0 0 0 0 force @a" << endl;
				}

			fout.close();
		}
		break;
		}
		delete bmp;
		GdiplusShutdown(gdiplustoken);
	}
	break;
	case 1001:
	{
		cout << "�����������" << endl;
		double x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		double x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		double tickall;
		cin >> tickall;

		double x = x2 - x1;
		double y = y2 - y1;
		double z = z2 - z1;

		double motionx = (0.02 * x) / (1 - pow(0.98, tickall));
		double motiony = (0.02 * (y + 2 * (tickall - 1))) / (1 - pow(0.98, (tickall - 1))) - 1.96;
		double motionz = (0.02 * z) / (1 - pow(0.98, tickall));

		cout << "summon falling_block ~ ~0.5 ~ {BlockState:{Name:\"minecraft:redstone_block\"},Time:1,Motion:[" << fixed << setprecision(14) << motionx << "," << motiony << "," << motionz << "]}" << endl;
		for (double i = 0; i <= tickall; i++)
		{
			cout << fixed << setprecision(0) << i << ".";
			cout << fixed << setprecision(14) << "Hy=" << (motiony + 1.96) * (1 - pow(0.98, i)) / 0.02 - 2 * i << endl;
		}
		for (double i = 0; i <= tickall; i++)
		{
			cout << fixed << setprecision(0) << i << ".";
			cout << fixed << setprecision(14) << "Vy=" << (motiony + 1.96) * pow(0.98, i) - 1.96 << endl;
		}
	}
	break;
	case 1002:
	{
		cout << "�����������" << endl;
		float x1, y1, z1;
		cin >> x1 >> y1 >> z1;
		cout << "�����յ�����" << endl;
		float x2, y2, z2;
		cin >> x2 >> y2 >> z2;
		cout << "����TP�ܶ�" << endl;//ÿtickִ�ж���ָ��
		int tickchange;
		cin >> tickchange;
		cout << "����ʱ���ܳ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int tickall;
		cin >> tickall;
		cout << "�����ʼ�Ƕ�" << endl;//�ڶ���tick��ִ��ȫ��ָ��
		int rotsnow;
		cin >> rotsnow;
		cout << "���뺯������" << endl;
		string fname;
		cin >> fname;

		float x, y, z;//��ֵ
		x = x2 - x1;
		y = y2 - y1;
		z = z2 - z1;

		float a, b, c;//ֱ��ͶӰ
		a = x / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		b = y / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		c = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));

		int i = 0;

		for (float k = 0; k <= (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))); k += ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / (tickall * tickchange)))
		{
			cx[i] = ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / (tickall * tickchange)) * a;
			cy[i] = ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / (tickall * tickchange)) * b;
			cz[i] = ((sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) / (tickall * tickchange)) * c;
			i++;
		}

		int doc = 0;//ÿ���ļ��м���
		int docchange = 0;//�ļ�����

		for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			for (int doc = 0; doc < tickchange; doc++)//ѭ�����
			{
				functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
					<< "tp"
					<< fixed << setprecision(8)
					<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop] << endl;
				jsonoutloop++;
			}
			functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
			functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
			docchange++;
			docc = to_string(docchange);
			string funname = fname + "_" + docc;
			functioncout << "schedule function minecraft:" << funname << " 1t";
			functioncout.close();
			if (docchange == tickall)//���һ���ļ����
			{
				string docc = to_string(docchange);
				string docname = fname + "_" + docc + ".mcfunction";
				ofstream functioncout(docname);
				functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
					<< "tp"
					<< fixed << setprecision(8)
					<< " ~" << x << " ~" << y << " ~" << z << endl;
				functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
				functioncout.close();
			}
			else
				jsonoutloop--;
		}

		string docname = fname + ".mcfunction";//������
		ofstream functioncout(docname);
		functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Marker:1,HandItems:[{id:\"minecraft:snowball\",Count:1b}],Rotation:[" << rotsnow << "]}" << endl;
		functioncout << "function minecraft:" << fname << "_0";
		functioncout.close();

	}
	break;
	}

	cout << "������ϣ���лʹ�ã�" << endl << "��������MYHZZD����" << endl;
	system("pause");
	return 0;
}

int basic_rotate(int i)
{
	cout << "������ת�Ƕ�:";
	float rot1, rot2, rot3;
	cin >> rot1 >> rot2 >> rot3;
	for (int j = 0; j <= i; j++)
	{
		float angle, l;

		angle = atan2(cz[j], cx[j]);
		angle += rot1 * 3.1415926 / 180;
		l = sqrt(pow(cx[j], 2) + pow(cz[j], 2));
		cx[j] = l * cos(angle);
		cz[j] = l * sin(angle);

		angle = atan2(cy[j], cx[j]);
		angle += rot2 * 3.1415926 / 180;
		l = sqrt(pow(cx[j], 2) + pow(cy[j], 2));
		cx[j] = l * cos(angle);
		cy[j] = l * sin(angle);

		angle = atan2(cy[j], cz[j]);
		angle += rot3 * 3.1415926 / 180;
		l = sqrt(pow(cz[j], 2) + pow(cy[j], 2));
		cz[j] = l * cos(angle);
		cy[j] = l * sin(angle);
	}
	return 0;
}

int comproportionation(int i)
{
	cout << "������нǶ�:";
	float rot1, rot2;
	cin >> rot1 >> rot2;
	for (int j = 0; j <= i; j++)
	{
		float angle = atan2(cz[j], cx[j]);
		angle += rot1 * 3.1415926 / 180;
		float lxz = sqrt(pow(cx[j], 2) + pow(cz[j], 2));
		float angle2 = atan2(cy[j], lxz);
		angle2 += rot2 * 3.1415926 / 180;
		float lxyz = sqrt(pow(lxz, 2) + pow(cy[j], 2));
		lxz = lxyz * cos(angle2);
		cy[j] = lxyz * sin(angle2);
		cx[j] = lxz * cos(angle);
		cz[j] = lxz * sin(angle);
	}
	return 0;
}

string writefunction_m1(int i, int x, int y, int z, int tickchange, int tickall, string fname)
{
	int doc = 0;//ÿ���ļ��м���
	int docchange = 0;//�ļ�����

	for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
	{
		string docc = to_string(docchange);
		string docname = fname + "_" + docc + ".mcfunction";
		ofstream functioncout(docname);
		for (int doc = 0; doc < tickchange; doc++)//ѭ�����
		{
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle minecraft:end_rod"
				<< fixed << setprecision(8)
				<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
				<< " 0 0 0"
				<< " 0"
				<< " 0 force @a" << endl;
			jsonoutloop++;
		}
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
		docchange++;
		docc = to_string(docchange);
		string funname = fname + "_" + docc;
		functioncout << "schedule function minecraft:" << funname << " 1t";
		functioncout.close();
		if (docchange == tickall)//���һ���ļ����
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle minecraft:end_rod"
				<< fixed << setprecision(8)
				<< " ~" << x << " ~" << y << " ~" << z
				<< " 0 0 0"
				<< " 0"
				<< " 0 force @a" << endl;
			functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
			functioncout.close();
		}
		else
			jsonoutloop--;
	}

	string docname = fname + ".mcfunction";//������
	ofstream functioncout(docname);
	functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
	functioncout << "function minecraft:" << fname << "_0";
	functioncout.close();

	return fname;
}

string writefunction_m2(int i, int x, int y, int z, int tickchange, int tickall, string fname)
{
	cout << "���������ɫ" << endl;
	int red1, green1, blue1;
	cin >> red1 >> green1 >> blue1;
	cout << "�����յ���ɫ" << endl;
	int red2, green2, blue2;
	cin >> red2 >> green2 >> blue2;
	cout << "������������" << endl;//���Ӵ���ʱ��
	int pptime;
	cin >> pptime;
	cout << "�������ɾ���" << endl;//���Ӵ���ʱ��
	int psize;
	cin >> psize;
	cout << "����������������" << endl;//���Ӵ���ʱ��
	int pcount;
	cin >> pcount;

	int doc = 0;//ÿ���ļ��м���
	int docchange = 0;//�ļ�����

	for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
	{
		string docc = to_string(docchange);
		string docname = fname + "_" + docc + ".mcfunction";
		ofstream functioncout(docname);
		for (int doc = 0; doc < tickchange; doc++)//ѭ�����
		{
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle soy:life_color_particle "
				<< fixed << setprecision(0)
				<< (red1 + docchange * floor((red2 - red1) / tickall)) * 65536 + (green1 + docchange * floor((green2 - green1) / tickall)) * 256 + (blue1 + docchange * floor((blue2 - blue1) / tickall))
				<< " " << pptime << " 1"
				<< fixed << setprecision(8)
				<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
				<< " 0.2 0.2 0.2"
				<< " " << (11.0 * psize) / 0.2
				<< " " << pcount << " force @a" << endl;
			jsonoutloop++;
		}
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
		docchange++;
		docc = to_string(docchange);
		string funname = fname + "_" + docc;
		functioncout << "schedule function minecraft:" << funname << " 1t";
		functioncout.close();
		if (docchange == tickall)//���һ���ļ����
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle soy:life_color_particle "
				<< fixed << setprecision(0)
				<< (red1 + docchange * floor((red2 - red1) / tickall)) * 65536 + (green1 + docchange * floor((green2 - green1) / tickall)) * 256 + (blue1 + docchange * floor((blue2 - blue1) / tickall))
				<< " " << pptime << " 1"
				<< fixed << setprecision(8)
				<< " ~" << x << " ~" << y << " ~" << z
				<< " 0.2 0.2 0.2"
				<< " " << (11.0 * psize) / 0.2
				<< " " << pcount << " force @a" << endl;
			functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
			functioncout.close();
		}
		else
			jsonoutloop--;
	}

	string docname = fname + ".mcfunction";//������
	ofstream functioncout(docname);
	functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
	functioncout << "function minecraft:" << fname << "_0";
	functioncout.close();

	return fname;
}

string writefunction_m3(int i, int x, int y, int z, int tickchange, int tickall, string fname)
{
	cout << "���������ɫ" << endl;
	int red1, green1, blue1;
	cin >> red1 >> green1 >> blue1;
	cout << "�����յ���ɫ" << endl;
	int red2, green2, blue2;
	cin >> red2 >> green2 >> blue2;
	cout << "������������" << endl;//���Ӵ���ʱ��
	int pptime;
	cin >> pptime;

	int doc = 0;//ÿ���ļ��м���
	int docchange = 0;//�ļ�����

	for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
	{
		string docc = to_string(docchange);
		string docname = fname + "_" + docc + ".mcfunction";
		ofstream functioncout(docname);
		for (int doc = 0; doc < tickchange; doc++)//ѭ�����
		{
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle soy:life_color_particle "
				<< fixed << setprecision(0)
				<< (red1 + docchange * floor((red2 - red1) / tickall)) * 65536 + (green1 + docchange * floor((green2 - green1) / tickall)) * 256 + (blue1 + docchange * floor((blue2 - blue1) / tickall))
				<< " " << pptime << " 1"
				<< fixed << setprecision(8)
				<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
				<< " 0 0 0"
				<< " 0"
				<< " 0 force @a" << endl;
			jsonoutloop++;
		}
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
		docchange++;
		docc = to_string(docchange);
		string funname = fname + "_" + docc;
		functioncout << "schedule function minecraft:" << funname << " 1t";
		functioncout.close();
		if (docchange == tickall)//���һ���ļ����
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle soy:life_color_particle "
				<< fixed << setprecision(0)
				<< (red1 + docchange * floor((red2 - red1) / tickall)) * 65536 + (green1 + docchange * floor((green2 - green1) / tickall)) * 256 + (blue1 + docchange * floor((blue2 - blue1) / tickall))
				<< " " << pptime << " 1"
				<< fixed << setprecision(8)
				<< " ~" << x << " ~" << y << " ~" << z
				<< " 0 0 0"
				<< " 0"
				<< " 0 force @a" << endl;
			functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
			functioncout.close();
		}
		else
			jsonoutloop--;
	}

	string docname = fname + ".mcfunction";//������
	ofstream functioncout(docname);
	functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
	functioncout << "function minecraft:" << fname << "_0";
	functioncout.close();

	return fname;
}

string writefunction_m4(int i, int x, int y, int z, int tickchange, int tickall, string fname)
{
	cout << "���������ɫ" << endl;
	int red1, green1, blue1;
	cin >> red1 >> green1 >> blue1;
	cout << "�����յ���ɫ" << endl;
	int red2, green2, blue2;
	cin >> red2 >> green2 >> blue2;
	cout << "������������" << endl;//���Ӵ���ʱ��
	int pptime;
	cin >> pptime;

	int doc = 0;//ÿ���ļ��м���
	int docchange = 0;//�ļ�����

	for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
	{
		string docc = to_string(docchange);
		string docname = fname + "_" + docc + ".mcfunction";
		ofstream functioncout(docname);
		for (int doc = 0; doc < tickchange; doc++)//ѭ�����
		{
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle soy:life_color_particle "
				<< fixed << setprecision(0)
				<< (red1 + docchange * floor((red2 - red1) / tickall)) * 65536 + (green1 + docchange * floor((green2 - green1) / tickall)) * 256 + (blue1 + docchange * floor((blue2 - blue1) / tickall))
				<< " " << pptime << " 1"
				<< fixed << setprecision(8)
				<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
				<< " " << cx[jsonoutloop + i + 1] << " " << cy[jsonoutloop + i + 1] << " " << cz[jsonoutloop + i + 1]
				<< " 0.09090909"
				<< " 0 force @a" << endl;
			jsonoutloop++;
		}
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
		docchange++;
		docc = to_string(docchange);
		string funname = fname + "_" + docc;
		functioncout << "schedule function minecraft:" << funname << " 1t";
		functioncout.close();
		if (docchange == tickall)//���һ���ļ����
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle soy:life_color_particle "
				<< fixed << setprecision(0)
				<< (red1 + docchange * floor((red2 - red1) / tickall)) * 65536 + (green1 + docchange * floor((green2 - green1) / tickall)) * 256 + (blue1 + docchange * floor((blue2 - blue1) / tickall))
				<< " " << pptime << " 1"
				<< fixed << setprecision(8)
				<< " ~" << x << " ~" << y << " ~" << z
				<< " " << cx[jsonoutloop + i + 1] << " " << cy[jsonoutloop + i + 1] << " " << cz[jsonoutloop + i + 1]
				<< " 0.09090909"
				<< " 0 force @a" << endl;
			functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
			functioncout.close();
		}
		else
			jsonoutloop--;
	}

	string docname = fname + ".mcfunction";//������
	ofstream functioncout(docname);
	functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
	functioncout << "function minecraft:" << fname << "_0";
	functioncout.close();

	return fname;
}

string writefunction_m5(int i, int x, int y, int z, int tickchange, int tickall, string fname)
{

	int doc = 0;//ÿ���ļ��м���
	int docchange = 0;//�ļ�����

	for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
	{
		string docc = to_string(docchange);
		string docname = fname + "_" + docc + ".mcfunction";
		ofstream functioncout(docname);
		for (int doc = 0; doc < tickchange; doc++)//ѭ�����
		{
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle minecraft:end_rod"
				<< fixed << setprecision(8)
				<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
				<< " " << cx[jsonoutloop + i + 1] << " " << cy[jsonoutloop + i + 1] << " " << cz[jsonoutloop + i + 1]
				<< " 0.09090909"
				<< " 0 force @a" << endl;
			jsonoutloop++;
		}
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
		docchange++;
		docc = to_string(docchange);
		string funname = fname + "_" + docc;
		functioncout << "schedule function minecraft:" << funname << " 1t";
		functioncout.close();
		if (docchange == tickall)//���һ���ļ����
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle minecraft:end_rod"
				<< fixed << setprecision(8)
				<< " ~" << x << " ~" << y << " ~" << z
				<< " " << cx[jsonoutloop + i + 1] << " " << cy[jsonoutloop + i + 1] << " " << cz[jsonoutloop + i + 1]
				<< " 0.09090909"
				<< " 0 force @a" << endl;
			functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
			functioncout.close();
		}
		else
			jsonoutloop--;
	}

	string docname = fname + ".mcfunction";//������
	ofstream functioncout(docname);
	functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
	functioncout << "function minecraft:" << fname << "_0";
	functioncout.close();

	return fname;
}

string writefunction_m6(int i, int x, int y, int z, int tickchange, int tickall, string fname)
{
	int doc = 0;//ÿ���ļ��м���
	int docchange = 0;//�ļ�����

	for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
	{
		string docc = to_string(docchange);
		string docname = fname + "_" + docc + ".mcfunction";
		ofstream functioncout(docname);
		for (int doc = 0; doc < tickchange; doc++)//ѭ�����
		{
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle minecraft:end_rod"
				<< fixed << setprecision(8)
				<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
				<< " 0 -100 0"
				<< " 100"
				<< " 0 force @a" << endl;
			jsonoutloop++;
		}
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
		docchange++;
		docc = to_string(docchange);
		string funname = fname + "_" + docc;
		functioncout << "schedule function minecraft:" << funname << " 1t";
		functioncout.close();
		if (docchange == tickall)//���һ���ļ����
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle minecraft:end_rod"
				<< fixed << setprecision(8)
				<< " ~" << x << " ~" << y << " ~" << z
				<< " 0 -100 0"
				<< " 100"
				<< " 0 force @a" << endl;
			functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
			functioncout.close();
		}
		else
			jsonoutloop--;
	}

	string docname = fname + ".mcfunction";//������
	ofstream functioncout(docname);
	functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
	functioncout << "function minecraft:" << fname << "_0";
	functioncout.close();

	return fname;
}

string writefunction_m7(int i, int x, int y, int z, int tickchange, int tickall, string fname)
{
	cout << "���������ɫ" << endl;
	int red1, green1, blue1;
	cin >> red1 >> green1 >> blue1;
	cout << "�����յ���ɫ" << endl;
	int red2, green2, blue2;
	cin >> red2 >> green2 >> blue2;
	int pptime;
	pptime = 1;

	int doc = 0;//ÿ���ļ��м���
	int docchange = 0;//�ļ�����

	for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
	{
		string docc = to_string(docchange);
		string docname = fname + "_" + docc + ".mcfunction";
		ofstream functioncout(docname);
		for (int doc = 0; doc < tickchange; doc++)//ѭ�����
		{
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle soy:life_color_particle "
				<< fixed << setprecision(0)
				<< (red1 + docchange * floor((red2 - red1) / tickall)) * 65536 + (green1 + docchange * floor((green2 - green1) / tickall)) * 256 + (blue1 + docchange * floor((blue2 - blue1) / tickall))
				<< " " << pptime << " 1"
				<< fixed << setprecision(8)
				<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
				<< " 0 0 0"
				<< " 0"
				<< " 0 force @a" << endl;
			jsonoutloop++;
		}
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
		docchange++;
		docc = to_string(docchange);
		string funname = fname + "_" + docc;
		functioncout << "schedule function minecraft:" << funname << " 1t";
		functioncout.close();
		if (docchange == tickall)//���һ���ļ����
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle soy:life_color_particle "
				<< fixed << setprecision(0)
				<< (red1 + docchange * floor((red2 - red1) / tickall)) * 65536 + (green1 + docchange * floor((green2 - green1) / tickall)) * 256 + (blue1 + docchange * floor((blue2 - blue1) / tickall))
				<< " " << pptime << " 1"
				<< fixed << setprecision(8)
				<< " ~" << x << " ~" << y << " ~" << z
				<< " 0 0 0"
				<< " 0"
				<< " 0 force @a" << endl;
			functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
			functioncout.close();
		}
		else
			jsonoutloop--;
	}

	string docname = fname + ".mcfunction";//������
	ofstream functioncout(docname);
	functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
	functioncout << "function minecraft:" << fname << "_0";
	functioncout.close();

	return fname;
}

string writefunction_m8(int i, int x, int y, int z, int density, int tickall, string fname)
{
	int doc = 0;//ÿ���ļ��м���
	int docchange = 0;//�ļ�����
	int tickchange;
	tickchange = 8192;

	for (int jsonoutloop = 0; jsonoutloop < i; jsonoutloop++)
	{
		string docc = to_string(docchange);
		string docname = fname + "_" + docc + ".mcfunction";
		ofstream functioncout(docname);
		for (int doc = 0; doc < tickchange; doc++)//ѭ�����
		{
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle minecraft:end_rod"
				<< fixed << setprecision(8)
				<< " ~" << cx[jsonoutloop] << " ~" << cy[jsonoutloop] << " ~" << cz[jsonoutloop]
				<< " 0 0 0"
				<< " 0"
				<< " 0 force @a" << endl;
			tickchange = floor(flexible_argument[jsonoutloop] * density);
			jsonoutloop++;
		}
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] add " << docchange + 1 << "" << endl;
		functioncout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange + 1 << "] remove " << docchange << "" << endl;
		docchange++;
		docc = to_string(docchange);
		string funname = fname + "_" + docc;
		functioncout << "schedule function minecraft:" << funname << " 1t";
		functioncout.close();
		if (docchange == tickall)//���һ���ļ����
		{
			string docc = to_string(docchange);
			string docname = fname + "_" + docc + ".mcfunction";
			ofstream functioncout(docname);
			functioncout << "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << docchange << "] at @s run "
				<< "particle minecraft:end_rod"
				<< fixed << setprecision(8)
				<< " ~" << x << " ~" << y << " ~" << z
				<< " 0 0 0"
				<< " 0"
				<< " 0 force @a" << endl;
			functioncout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << tickall << "]";
			functioncout.close();
		}
		else
			jsonoutloop--;
	}

	string docname = fname + ".mcfunction";//������
	ofstream functioncout(docname);
	functioncout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
	functioncout << "function minecraft:" << fname << "_0";
	functioncout.close();

	return fname;
}

int writefunction_m21(int i)
{
	cout << "���뺯������:";
	string fname;
	cin >> fname;
	string funname = fname + ".mcfunction";
	ofstream funcout(funname);
	for (int j = 0; j < i; j++)
		funcout << "particle minecraft:end_rod ~" << fixed << setprecision(8) << cx[j] << " ~" << cy[j] << " ~" << cz[j] << " 0 0 0 0 0 force @a" << endl;
	funcout.close();
	return 0;
}

int writefunction_m22(int i)
{
	cout << "���뺯������:";
	string fname;
	cin >> fname;
	cout << "�Ƿ���ѭ������������ʱ�䣨Y/N��:";
	string loop;
	cin >> loop;

	if (loop == "Y" || loop == "y")
	{
		string funname = fname + ".mcfunction";
		ofstream funcout(funname);
		for (int j = 0; j < i; j++)
			funcout << "particle minecraft:end_rod ~" << fixed << setprecision(8) << cx[j] << " ~" << cy[j] << " ~" << cz[j] << " 0 -100 0 10 0 force @a" << endl;
		funcout.close();
	}
	else
	{
		cout << "���������ʱ��:";
		int looptime;
		cin >> looptime;
		for (int jj = 0; jj <= looptime; jj++)
		{
			string jjj = to_string(jj);
			string funname = fname + "_" + jjj + ".mcfunction";
			ofstream funcout(funname);
			for (int j = 0; j < i; j++)
				funcout
				<< "execute as @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << jj << "] at @s run "
				<< "particle minecraft:end_rod ~" << fixed << setprecision(8) << cx[j] << " ~" << cy[j] << " ~" << cz[j] << " 0 -100 0 10 0 force @a" << endl;
			string jjjj = to_string(jj + 1);
			funname = fname + "_" + jjjj;
			funcout << "schedule function minecraft:" << funname << " 1t" << endl;
			funcout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << jj << "] add " << jj + 1 << "" << endl;
			if (jj != looptime)
				funcout << "tag @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << jj + 1 << "] remove " << jj << "";
			else
				funcout << "kill @e[type=minecraft:armor_stand,tag=" << fname << ",tag=" << looptime + 1 << "]";
			funcout.close();
		}
		string funname = fname + ".mcfunction";
		ofstream funcout(funname);
		funcout << "summon minecraft:armor_stand ~ ~ ~ {Tags:[\"" << fname << "\",\"0\"],Invisible:1,Marker:1}" << endl;
		funcout << "function minecraft:" << fname << "_0";
		funcout.close();
	}
	return 0;
}

int writefunction_m23(int i)
{
	cout << "���뺯������:";
	string fname;
	cin >> fname;
	cout << "����ƽ�Ʒ���:";
	float posx, posy, posz;
	cin >> posx >> posy >> posz;
	float posxy = max(posx, posy);
	float pos = max(posxy, posz);
	if (pos == 0)
		pos = 1;
	cout << "�����ٶȲ���:";
	float v;
	cin >> v;
	string funname = fname + ".mcfunction";
	ofstream funcout(funname);
	for (int j = 0; j < i; j++)
		funcout << "particle minecraft:end_rod ~" << fixed << setprecision(8) << cx[j] << " ~" << cy[j] << " ~" << cz[j]
		<< " " << posx / pos << " " << posy / pos << " " << posz / pos << " " << v << " 0 force @a" << endl;
	funcout.close();
	return 0;
}

int writefunction_m24(int i)
{
	cout << "������ɢ�ٶ�:";
	float size;
	cin >> size;
	cout << "���뺯������:";
	string fname;
	cin >> fname;
	string funname = fname + ".mcfunction";
	ofstream funcout(funname);
	for (int j = 0; j < i; j++)
		funcout << "particle minecraft:end_rod ~ ~ ~ " << fixed << setprecision(8) << cx[j] << " " << cy[j] << " " << cz[j] << " " << size << " 0 force @a" << endl;
	funcout.close();
	return 0;
}

float normal_vector_rot(float dx, float dy, float dz, float x, float y, float z, string n)
{
	float drotxz = atan2(dz, dx);
	float drotyxz = atan2(dy, sqrt(pow(dx, 2) + pow(dz, 2)));
	float rx1 = sin(drotxz);
	float ry1 = 0;
	float rz1 = -cos(drotxz);
	float rx2 = -cos(drotxz) * sin(drotyxz);
	float ry2 = cos(drotyxz);
	float rz2 = -sin(drotxz) * sin(drotyxz);
	float zx = (rx1 * x) + (z * rx2);
	float zy = (ry1 * x) + (z * ry2);
	float zz = (rz1 * x) + (z * rz2);
	if (n == "x")
		return zx;
	else if (n == "y")
		return zy;
	else if (n == "z")
		return zz;
}
