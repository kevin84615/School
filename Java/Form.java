package hw5;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class hw5Form  extends JFrame
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JLabel[]  lab ={new JLabel("GCD"),new JLabel("LCM"),new JLabel("Value1"),new JLabel("Value2")};
	private JTextField[] tbx={new JTextField(20),new JTextField(20),new JTextField(20),new JTextField(20)};
	private JButton btn = new JButton("Start");
	public hw5Form()
	{
		super("Form1");
		setLayout(new FlowLayout());
		tbx[0].setEnabled(false);
		tbx[1].setEnabled(false);
		for (int i = 0 ;i<=3 ; i++)
		{
			add(lab[i]);
			add(tbx[i]);
		}//end of for
		add(btn);
		btnHandler handler = new btnHandler();
		btn.addActionListener(handler);
		tbx[3].addActionListener(handler);
	}//end of instruction
	class btnHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			//JOptionPane.showMessageDialog(null, "Enter Event TextField");
			int t1=Integer.parseInt(tbx[2].getText());
			int t2=Integer.parseInt(tbx[3].getText());
			int t3=t1*t2;
			while (true)
			{//gcd lcm start
				if (t1>t2)
				{
					t1=t1%t2;
					if (t1==0)
					{
						tbx[0].setText(String.valueOf(t2));
						tbx[1].setText(String.valueOf(t3/t2));
						break;
					}
				}
				else
				{
					t2=t2%t1;
					if (t2==0)
					{
						tbx[0].setText(String.valueOf(t1));
						tbx[1].setText(String.valueOf(t3/t1));
						break;
					}
				}
			}//end of gcd lcm
		}//end of actionPerformed
	}//end of btnHandler
}//end of hw5Form
