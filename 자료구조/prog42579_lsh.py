def solution(genres, plays):
    answer = []
    genre_total_play = {}
    total_map = {}
    for i in range(len(genres)):
        genre = genres[i]
        if genre not in genre_total_play:
            genre_total_play[genre] = 0
            total_map[genre] = []

        genre_total_play[genre] += plays[i]
        total_map[genre].append((i, -plays[i]))

    total_play_list = []
    sorted_genre = []
    for genre, plays in genre_total_play.items():
        total_play_list.append((-plays, genre))

    total_play_list.sort(key=lambda x: x[0])

    for plays, genre in total_play_list:
        sorted_genre.append(genre)

    for genre in sorted_genre:
        play_info = total_map[genre]

        play_info.sort(key=lambda x: (x[1], x[0]))

        cnt = 0

        for info in play_info:
            if cnt == 2: break
            answer.append(info[0])
            cnt+= 1

    return answer