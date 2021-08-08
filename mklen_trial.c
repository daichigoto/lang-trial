#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int
main(void)
{
	// 文字数は16、ターミナル幅は26
	const char buf[] = "１２３４５六七八九十ABCDEF";
	const char *p;
	p = buf;

	// 文字数を格納
	int number_of_chars = 0;

	// ターミナルでの文字列の幅を格納（半角分がいくつかでカウント）
	int width_in_terminal = 0;

	// 現在のロケールを適用。この処理を行うことでmblen()がロケールを
	// 加味した文字バイト数を返すようになる。
	setlocale(LC_CTYPE, "");

	while('\0' != *p){
		int char_bytes = mblen(p, MB_CUR_MAX);

		// 文字数を加算
		number_of_chars++;

		// ターミナルの幅を加算
		//
		// (より正確に判断するには、エンコードごとに
		//  文字の種類を判断して幅を計算する)
		if (1 == char_bytes) {
			// 1バイトは半角と仮定
			width_in_terminal += 1;
		}
		else {
			// 2バイト以上の文字は全角と仮定
			width_in_terminal += 2;
		}

		p += char_bytes;
	}

	printf("文字数: %d\n", number_of_chars );
	printf("ターミナル幅: %d\n", width_in_terminal);

	return 0;
}
