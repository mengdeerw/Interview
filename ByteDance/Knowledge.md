https://www.1point3acres.com/bbs/thread-577293-8-1.html

答1
把小文件copy到10000个服务器这种问题个人感觉还是很实际的。考虑以下两个办法：1）一台台服务器传(e.g. for server in ${server_name[@]}; do scp $file_name $server; done)；2）并行传（e.g. for server in ${server_name[@]}; do scp $file_name $server & done）。第一个方法时间会很长，所以不可取；第二方法无论是transfer to/from，那个单台server都会非常卡，毕竟有10000个tcp连接。如果是我写脚本的话，会把这10000拆分成100 x 100。也就是把把文件并行传到100个服务器，比如(0,100,200,300,...)，然后再让0号服务器并行传到1-99号服务器。这样总体时间会很短，100个tcp并行连接的开销也不会特别大。

答2
和同学讨论了一下这个问题，这个“小文件”应该是集群的配置文件，要sync到1w台服务器上，应该就是每个服务器做一个process，隔一段时间去pull这个配置文件就行了。字节跳动自己做backend，不用公有云，比较省钱。这个配置文件用一台服务器做主机，再拿两台来备份下差不多就够了。

答3
其实是个副本复制的问题 consensus protocol就可以做 paxos，raft，zab都是基于leader的，在参与者多的情况下效率很低，而且leader挂了，比较麻烦，要重选leader。针对p2p的情况，可以用最终一致性的gossip协议。文件比较小的话，应该用不到一些bittorrent的协议。
https://youtu.be/vEk3VDC0J7k
