/*==========================================================================
 *
 *  Copyright (C) 2002-2008 Jumpei Isshiki. All Rights Reserved.
 *
 *  ○ゲームタイトル：ALERT(アラート) for GP2X
 *  ○ジャンル      ：横画面縦スクロールボス自動生成シューティング
 *  ○プレイ人数    ：一人
 *  ○バージョン    ：0.14
 *  ○公開日付      ：2008/01/06
 *  ○更新日付      ：2008/01/15
 *
 ==========================================================================*/

＜はじめに＞
  「ALERT」は、いわゆるボスオンパのシューティングですが、そのボスを自動生成し
てみました。
   「P/ECE」という携帯ゲーム機で作ったのを、GP2X に移植してみました。

＜ルール＞

  3WAYやレーザー（？）ショットを駆使して、ボスをひたすら倒してください。
  自機が敵弾や敵本体に接触すると、やられます。
  ボスやオプションを破壊すると、画面中の弾がボーナスアイテムに変化します。た
くさん取って点数を稼ぎましょう。
  タイトル画面で放置してるとデモプレイが再生されるので、それを見てどういうゲ
ームか理解すると良いでしょう。
  デモプレイはAボタンで終了し、タイトル画面に戻ります。


・操作説明
  自機移動          ：十字キー（と言えるのか？）
  3WAYショット      ：A ボタン
  レーザーショット  ：A ボタンをしばらく押しっぱなし
  メニュー決定      ：B ボタン
  ゲーム中断        ：SELECT ボタン（ゲーム中のみ）
  ゲーム終了        ：L+R+HOME ボタン/タイトルメニューの「EXIT」を選択

  ボリューム－      ：音量を下げる（最低０）
  ボリューム＋      ：音量を上げる（最高１２８）


・メニュー説明
  EASY GAME       全６レベル。それなりにやさしいモード。
  HARD GAME       全１２レベル。わりと難しくなっていくモード。
  ENDLESS         永遠に終わらないモード。
  EXIT            ALERTを終了し、ランチャに戻る。


・ボーナスチップとチップコンボ
  ボスやオプションを破壊する事で得られる「ボーナスチップ」。破壊した時に画面中
にある敵の弾がチップに変化します。
  チップはちょっとの間その場に滞在し、その後自機に向かって飛んできます。
  そのチップは、連続して取ると「チップコンボ」というボーナスが得られます。チッ
プコンボは・・・、

  100pts  →  200pts  →  300pts  →  400pts  →  ・・・

  という感じで、100点ずつ加算されていきます。点数は、画面右上に表示されます。
  チップコンボは、一定時間内にチップを取ることで加算されるので、連続で破壊して
連続でチップに変えることで、更なるコンボを稼ぐことができます。


・エクステンド
  50,000点、200,000点、600,000点、1,000,000点、以後1,000,000点ごとにエクステン
ドします。


＜謝辞＞
  このゲームに様々な意見を下さった友人、知人に、深く感謝いたします。

  また「ALERT for GP2X」は、以下のツールを本ソフト作成のために使わせていただきま
した。
  ツール作成者の方に感謝します。

  ＜オブジェクトデザイン＞
  EDGE Version 1.19
  作者：Takabo soft network
  URL:http://www.tkb-soft.hmcbest.com/

  ＜効果音作成＞
  KanaWave Version 0.12
  作者：Ｓｈｏｕ／河合章悟（さくらやまスクエア）
  URL:http://homepage1.nifty.com/sakurayama/

  ＜ＢＧＭ作成＞
  Sonic Foundry ACID Style - dj Version 3.0a(Build 241)
  作者：Copyright(C) 1997-2001 Sonic Foundry,Inc.
  URL:http://sonicfoundry.com/acid/


＜連絡＞

・御意見、ご感想などはこちらまで。
    ads00721@nifty.com


＜更新履歴＞

  2008/01/15    Ver 0.14    処理速度をちょっと向上。あまり感じられないかしら。
                            HARD の難易度を上げてみた。具体的には敵弾数と速度の
                            上昇。
                            HARD & ENDLESS のエクステンド数を MAX4 機に制限。
  2008/01/14    Ver 0.13    サウンドリクエストの遅延を解消。
                            ボリュームボタンで音量変更できるように対応。
                            ハイスコアと音量を残すように変更。
  2008/01/12    Ver 0.12    キーアサインを変更。恐らく GP2X 標準に。
                            処理落ちを軽減。
                            デモプレイの表示を変更。
  2008/01/10    Ver 0.11    敵弾の挙動が変なのを修正。
                            中断ボタンが B になっていたので SELECT に変更。
                            場所によって 0 除算を起こしていたので修正。
  2008/01/06    Ver 0.10    移植した。


＜最後に＞

  「GP2X」で動くということは、SDL な環境ならそれなりに簡単に移植できると思います。
  しかしこれ、作ったの６年前なんだなあ...。


＜ライセンス＞

ALERT for GP2X は BSDスタイルライセンスのもと配布されます。

<ENGLISH>
License
-------

Copyright 2008 HELLO WORLD PROJECT (Jumpei Isshiki). All rights reserved. 

Redistribution and use in source and binary forms, 
with or without modification, are permitted provided that 
the following conditions are met: 

 1. Redistributions of source code must retain the above copyright notice, 
    this list of conditions and the following disclaimer. 

 2. Redistributions in binary form must reproduce the above copyright notice, 
    this list of conditions and the following disclaimer in the documentation 
    and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, 
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND 
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL 
THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 


<JAPANESE>
ライセンス
-------

Copyright 2008 HELLO WORLD PROJECT (Jumpei Isshiki). All rights reserved. 

 1.ソースコード形式であれバイナリ形式であれ、変更の有無に 関わらず、以下の条件を
   満たす限りにおいて、再配布および使用を許可します。

 2.ソースコード形式で再配布する場合、上記著作権表示、 本条件書および下記責任限定
   規定を必ず含めてください。 

バイナリ形式で再配布する場合、上記著作権表示、 本条件書および下記責任限定規定を、
配布物とともに提供される文書 および/または 他の資料に必ず含めてください。 
本ソフトウェアは HELLO WORLD PROJECT によって、”現状のまま” 提供されるものとし
ます。 本ソフトウェアについては、明示黙示を問わず、 商用品として通常そなえるべき
品質をそなえているとの保証も、 特定の目的に適合するとの保証を含め、何の保証もな
されません。 事由のいかんを問わず、 損害発生の原因いかんを問わず、且つ、 責任の
根拠が契約であるか厳格責任であるか (過失その他) 不法行為であるかを問わず、
 HELLO WORLD PROJECT も寄与者も、 仮にそのような損害が発生する可能性を知らされて
いたとしても、 本ソフトウェアの使用から発生した直接損害、間接損害、偶発的な損害、
 特別損害、懲罰的損害または結果損害のいずれに対しても (代替品または サービスの提
供; 使用機会、データまたは利益の損失の補償; または、業務の中断に対する補償を含め) 
責任をいっさい負いません。
