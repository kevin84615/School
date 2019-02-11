package hw6;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class calculator extends JFrame
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int var1=0;
	private int op=0;
	private JTextField tbx=new JTextField();
	private JButton[] btn;
	private String[] str1 = { "0","=","c","+",
											   "1","2","3","-",
											   "4","5","6","*",
											   "7","8","9","/",
											   "A","B","C","D","E","F"};
	private String[] str2 = { "0","104","105","100",
											   "1","2","3","101",
											   "4","5","6","102",
											   "7","8","9","103",
											   "10","11","12","13","14","15"};
	private JRadioButton rbtn1=new JRadioButton("十進位");
	private JRadioButton rbtn2=new JRadioButton("十六進位");
	private JPanel[] pan;
	private ButtonGroup gp = new ButtonGroup();
	public calculator ()
	{
		super("Calculator");
		setLayout(new BorderLayout(10,10));
		int i;
		btn = new JButton[str1.length];
		for (i=0;i<str1.length;i++)
			btn[i] = new JButton(str1[i]);
		pan = new JPanel[5];
		for (i=0;i<5;i++)
			pan[i] = new JPanel();
		pan[0].setLayout(new GridLayout(4,4,5,5));
		for (i=0;i<16;i++)
			pan[0].add(btn[i]);
		pan[1].setLayout(new GridLayout(1,6,5,5));
		for (i=16;i<str1.length;i++)
			pan[1].add(btn[i]);
		pan[2].setLayout(new GridLayout(1,2,5,5));
		pan[2].add(rbtn1);
		pan[2].add(rbtn2);
		pan[3].setLayout(new BorderLayout(10,10));
		pan[3].add(pan[1],BorderLayout.NORTH);
		pan[3].add(pan[2],BorderLayout.SOUTH);
		add(tbx,BorderLayout.NORTH);
		add(pan[0],BorderLayout.CENTER);
		add(pan[3],BorderLayout.SOUTH);
		gp.add(rbtn1);
		gp.add(rbtn2);
		ButtonListener listener =new ButtonListener();
		for (i=0;i<str1.length;i++)
			btn[i].addActionListener(listener);
		RadioButtonHandler handler = new RadioButtonHandler();
		rbtn1.addItemListener(handler);
		rbtn2.addItemListener(handler);
		rbtn1.setSelected(true);
		tbx.setEnabled(false);
	}
	private class ButtonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			int key =getButton(e) ;
			if (key<16)
				tbx.setText(tbx.getText()+e.getActionCommand());
			else if (key < 104)
			{
				if (rbtn1.isSelected())
				{
					var1= Integer.parseInt( tbx.getText());
					tbx.setText("");
				}
				else
				{
					var1= Integer.parseInt( tbx.getText(),16);
					tbx.setText("");
				}
				op=key;
			}
			else if (key==104)
					tbx.setText(calc());
			else if (key==105)
			{
				var1=0;
				tbx.setText("");
				op=0;
			}
		}
	}
	private String calc()
	{
		String ans="" ;
		int i=0;
		if (rbtn1.isSelected())
		{
			switch (op)
			{
			case 100:
				i= var1 + Integer.parseInt(tbx.getText());
				break;
			case 101:
				i= var1 - Integer.parseInt(tbx.getText());
				break;
			case 102:
				i= var1 * Integer.parseInt(tbx.getText());
				break;
			case 103:
				i= var1 / Integer.parseInt(tbx.getText());
				break;
			}
			ans = Integer.toString(i);
		}
		else
			{
			switch (op)
			{
			case 100:
				i= var1 + Integer.parseInt(tbx.getText(),16);
				break;
			case 101:
				i= var1 - Integer.parseInt(tbx.getText(),16);
				break;
			case 102:
				i= var1 * Integer.parseInt(tbx.getText(),16);
				break;
			case 103:
				i= var1 / Integer.parseInt(tbx.getText(),16);
				break;
			}
			ans = Integer.toHexString(i);
		}
		return ans;
	}
	private int getButton(ActionEvent e)
	{
		int i ;
		for (i=0;i<str1.length;i++)
			if (e.getSource() == btn[i])
				return Integer.parseInt(str2[i]);
		return -1;
	}
	private class RadioButtonHandler implements ItemListener
	{
		public void itemStateChanged(ItemEvent e)
		{
			int i;
			if (e.getSource() != rbtn1)
				for (i=16 ;i<str1.length;i++)
					btn[i].setEnabled(true);
			else
				for (i=16 ;i<str1.length;i++)
					btn[i].setEnabled(false);
		}
	}
}
